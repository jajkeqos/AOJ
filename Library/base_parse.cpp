// * Example *
// 注意点なるべくgetlineを使用して読み込む
// string s;
// getline(cin, s);
// State begin = s.begin();
// int ans = expression(begin);
// cout << ans << endl;

// 構文解析用の基本処理
// AOJ 0109をベースにしている
// 構文解析についてはここを参照
// [構文解析Howto](https://gist.github.com/draftcode/1357281)

// 方針のまとめ
//
// 1.テンプレートを書く
// 2.expression, term, factor, numberのスケルトンを書く
// 3.factorとnumberを埋める
// 4.expressinとtermを埋める(最初に一つ下の部分式を一つだけパースした後に、あと
// はループで回しながら、足したり引いたりする。)
// 5.文字列の入力を行う
//
// デバッグ
// begin++; の代わりにconsume突っ込む
// begin++; のし忘れ
// cinとgetlineの混同でうまく読み込めていない
//
// 今回のBNF
// <四則演算の式> ::= <乗算除算の式> (+ or -) <乗算除算の式> (+ or -) ...
// <乗算除算の式> ::= <括弧か数> (* or /) <括弧か数> (* or /) ...
// <括弧か数>     ::= '(' <四則演算の式> ')' or <数>
// <数>           ::= .../

typedef string::const_iterator State;
class ParseError {};

// デバッグ用 begin++; するかわりに突っ込んで
// 来るはずのcharを入れて使う(もし外れていたら例外が飛ぶ)
void consume(State &begin, char expected);

// 四則演算
int expression(State &begin);
// 乗算除算
int term(State &begin);
// 括弧か数
int factor(State &begin);
// 数
int number(State &begin);

void consume(State &begin, char expected) {
  if (*begin == expected) {
    begin++;
  } else {
    cerr << "Expected '" << expected << "' but got '" << *begin << "'" << endl;
    cerr << "Rest string is '";
    while (*begin) {
      cerr << *begin++;
    }
    cerr << "'" << endl;
    throw ParseError();
  }
}

// 四則演算の式をパースして評価結果を返す
int expression(State &begin) {
  int ret = term(begin);

  while (1) {
    if (*begin == '+') {
      begin++;
      ret += term(begin);
    } else if (*begin == '-') {
      begin++;
      ret -= term(begin);
    } else {
      break;
    }
  }

  return ret;
}

// 乗算除算の式をパースして評価結果を返す
int term(State &begin) {
  int ret = factor(begin);

  while (1) {
    if (*begin == '*') {
      begin++;
      ret *= factor(begin);
    } else if (*begin == '/') {
      begin++;
      ret /= factor(begin);
    } else {
      break;
    }
  }

  return ret;
}

// カッコか数をパースして結果を返す
int factor(State &begin) {
  if (*begin == '(') {
    begin++;
    int ret = expression(begin);
    consume(begin, ')');
    return ret;
  } else {
    return number(begin);
  }
}

// 数字をパースする
int number(State &begin) {
  int ret = 0;

  while (isdigit(*begin)) {
    ret *= 10;
    ret += *begin - '0';
    begin++;
  }

  return ret;
}
