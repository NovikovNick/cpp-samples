#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define CASE_2 1
#define CASE_3 1
#define CASE_4 1
#define CASE_5 1
#define DEBUG 0

#include "../src/leetcode/word_search_ii.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<char>> board = {{'o', 'a', 'a', 'n'},
                                          {'e', 't', 'a', 'e'},
                                          {'i', 'h', 'k', 'r'},
                                          {'i', 'f', 'l', 'v'}};
  std::vector<std::string> words = {"oath", "pea", "eat", "rain"};
  // act
  auto res = solution.findWords(board, words);

  // assert
  BOOST_CHECK_EQUAL("eat", res[0]);
  BOOST_CHECK_EQUAL("oath", res[1]);
}
#endif  // !CASE_1

#if CASE_2
BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<char>> board = {{'a', 'b'}, {'c', 'd'}};
  std::vector<std::string> words = {"abcb"};
  // act
  auto res = solution.findWords(board, words);

  // assert
  BOOST_CHECK(res.empty());
}
#endif  // !CASE_2

#if CASE_3
BOOST_AUTO_TEST_CASE(case3) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<char>> board = {
      {{'a', 'b', 'c'}, 
      {'a', 'e', 'd'}, 
      {'a', 'f', 'g'}}};
  std::vector<std::string> words = {"abcdefg", "gfedcbaaa", "eaabcdgfa",
                                    "befa",    "dgc",       "ade"};
  // act
  auto res = solution.findWords(board, words);

  // assert
  BOOST_CHECK_EQUAL("abcdefg", res[0]);
  BOOST_CHECK_EQUAL("befa", res[1]);
  BOOST_CHECK_EQUAL("eaabcdgfa", res[2]);
  BOOST_CHECK_EQUAL("gfedcbaaa", res[3]);
}
#endif  // !CASE_3

#if CASE_4
BOOST_AUTO_TEST_CASE(case4) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<char>> board = {
      {'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a'},
      {'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b'},
      {'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a'},
      {'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b'},
      {'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a'},
      {'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b'},
      {'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a'},
      {'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b'},
      {'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a'},
      {'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b'}};

  std::vector<std::string> words = {
      "ababababaa", "ababababab", "ababababac", "ababababad", "ababababae",
      "ababababaf", "ababababag", "ababababah", "ababababai", "ababababaj",
      "ababababak", "ababababal", "ababababam", "ababababan", "ababababao",
      "ababababap", "ababababaq", "ababababar", "ababababas", "ababababat",
      "ababababau", "ababababav", "ababababaw", "ababababax", "ababababay",
      "ababababaz", "ababababba", "ababababbb", "ababababbc", "ababababbd",
      "ababababbe", "ababababbf", "ababababbg", "ababababbh", "ababababbi",
      "ababababbj", "ababababbk", "ababababbl", "ababababbm", "ababababbn",
      "ababababbo", "ababababbp", "ababababbq", "ababababbr", "ababababbs",
      "ababababbt", "ababababbu", "ababababbv", "ababababbw", "ababababbx",
      "ababababby", "ababababbz", "ababababca", "ababababcb", "ababababcc",
      "ababababcd", "ababababce", "ababababcf", "ababababcg", "ababababch",
      "ababababci", "ababababcj", "ababababck", "ababababcl", "ababababcm",
      "ababababcn", "ababababco", "ababababcp", "ababababcq", "ababababcr",
      "ababababcs", "ababababct", "ababababcu", "ababababcv", "ababababcw",
      "ababababcx", "ababababcy", "ababababcz", "ababababda", "ababababdb",
      "ababababdc", "ababababdd", "ababababde", "ababababdf", "ababababdg",
      "ababababdh", "ababababdi", "ababababdj", "ababababdk", "ababababdl",
      "ababababdm", "ababababdn", "ababababdo", "ababababdp", "ababababdq",
      "ababababdr", "ababababds", "ababababdt", "ababababdu", "ababababdv",
      "ababababdw", "ababababdx", "ababababdy", "ababababdz", "ababababea",
      "ababababeb", "ababababec", "ababababed", "ababababee", "ababababef",
      "ababababeg", "ababababeh", "ababababei", "ababababej", "ababababek",
      "ababababel", "ababababem", "ababababen", "ababababeo", "ababababep",
      "ababababeq", "ababababer", "ababababes", "ababababet", "ababababeu",
      "ababababev", "ababababew", "ababababex", "ababababey", "ababababez",
      "ababababfa", "ababababfb", "ababababfc", "ababababfd", "ababababfe",
      "ababababff", "ababababfg", "ababababfh", "ababababfi", "ababababfj",
      "ababababfk", "ababababfl", "ababababfm", "ababababfn", "ababababfo",
      "ababababfp", "ababababfq", "ababababfr", "ababababfs", "ababababft",
      "ababababfu", "ababababfv", "ababababfw", "ababababfx", "ababababfy",
      "ababababfz", "ababababga", "ababababgb", "ababababgc", "ababababgd",
      "ababababge", "ababababgf", "ababababgg", "ababababgh", "ababababgi",
      "ababababgj", "ababababgk", "ababababgl", "ababababgm", "ababababgn",
      "ababababgo", "ababababgp", "ababababgq", "ababababgr", "ababababgs",
      "ababababgt", "ababababgu", "ababababgv", "ababababgw", "ababababgx",
      "ababababgy", "ababababgz", "ababababha", "ababababhb", "ababababhc",
      "ababababhd", "ababababhe", "ababababhf", "ababababhg", "ababababhh",
      "ababababhi", "ababababhj", "ababababhk", "ababababhl", "ababababhm",
      "ababababhn", "ababababho", "ababababhp", "ababababhq", "ababababhr",
      "ababababhs", "ababababht", "ababababhu", "ababababhv", "ababababhw",
      "ababababhx", "ababababhy", "ababababhz", "ababababia", "ababababib",
      "ababababic", "ababababid", "ababababie", "ababababif", "ababababig",
      "ababababih", "ababababii", "ababababij", "ababababik", "ababababil",
      "ababababim", "ababababin", "ababababio", "ababababip", "ababababiq",
      "ababababir", "ababababis", "ababababit", "ababababiu", "ababababiv",
      "ababababiw", "ababababix", "ababababiy", "ababababiz", "ababababja",
      "ababababjb", "ababababjc", "ababababjd", "ababababje", "ababababjf",
      "ababababjg", "ababababjh", "ababababji", "ababababjj", "ababababjk",
      "ababababjl", "ababababjm", "ababababjn", "ababababjo", "ababababjp",
      "ababababjq", "ababababjr", "ababababjs", "ababababjt", "ababababju",
      "ababababjv", "ababababjw", "ababababjx", "ababababjy", "ababababjz",
      "ababababka", "ababababkb", "ababababkc", "ababababkd", "ababababke",
      "ababababkf", "ababababkg", "ababababkh", "ababababki", "ababababkj",
      "ababababkk", "ababababkl", "ababababkm", "ababababkn", "ababababko",
      "ababababkp", "ababababkq", "ababababkr", "ababababks", "ababababkt",
      "ababababku", "ababababkv", "ababababkw", "ababababkx", "ababababky",
      "ababababkz", "ababababla", "abababablb", "abababablc", "ababababld",
      "abababable", "abababablf", "abababablg", "abababablh", "ababababli",
      "abababablj", "abababablk", "ababababll", "abababablm", "ababababln",
      "abababablo", "abababablp", "abababablq", "abababablr", "ababababls",
      "abababablt", "abababablu", "abababablv", "abababablw", "abababablx",
      "abababably", "abababablz", "ababababma", "ababababmb", "ababababmc",
      "ababababmd", "ababababme", "ababababmf", "ababababmg", "ababababmh",
      "ababababmi", "ababababmj", "ababababmk", "ababababml", "ababababmm",
      "ababababmn", "ababababmo", "ababababmp", "ababababmq", "ababababmr",
      "ababababms", "ababababmt", "ababababmu", "ababababmv", "ababababmw",
      "ababababmx", "ababababmy", "ababababmz", "ababababna", "ababababnb",
      "ababababnc", "ababababnd", "ababababne", "ababababnf", "ababababng",
      "ababababnh", "ababababni", "ababababnj", "ababababnk", "ababababnl",
      "ababababnm", "ababababnn", "ababababno", "ababababnp", "ababababnq",
      "ababababnr", "ababababns", "ababababnt", "ababababnu", "ababababnv",
      "ababababnw", "ababababnx", "ababababny", "ababababnz", "ababababoa",
      "ababababob", "ababababoc", "ababababod", "ababababoe", "ababababof",
      "ababababog", "ababababoh", "ababababoi", "ababababoj", "ababababok",
      "ababababol", "ababababom", "ababababon", "ababababoo", "ababababop",
      "ababababoq", "ababababor", "ababababos", "ababababot", "ababababou",
      "ababababov", "ababababow", "ababababox", "ababababoy", "ababababoz",
      "ababababpa", "ababababpb", "ababababpc", "ababababpd", "ababababpe",
      "ababababpf", "ababababpg", "ababababph", "ababababpi", "ababababpj",
      "ababababpk", "ababababpl", "ababababpm", "ababababpn", "ababababpo",
      "ababababpp", "ababababpq", "ababababpr", "ababababps", "ababababpt",
      "ababababpu", "ababababpv", "ababababpw", "ababababpx", "ababababpy",
      "ababababpz", "ababababqa", "ababababqb", "ababababqc", "ababababqd",
      "ababababqe", "ababababqf", "ababababqg", "ababababqh", "ababababqi",
      "ababababqj", "ababababqk", "ababababql", "ababababqm", "ababababqn",
      "ababababqo", "ababababqp", "ababababqq", "ababababqr", "ababababqs",
      "ababababqt", "ababababqu", "ababababqv", "ababababqw", "ababababqx",
      "ababababqy", "ababababqz", "ababababra", "ababababrb", "ababababrc",
      "ababababrd", "ababababre", "ababababrf", "ababababrg", "ababababrh",
      "ababababri", "ababababrj", "ababababrk", "ababababrl", "ababababrm",
      "ababababrn", "ababababro", "ababababrp", "ababababrq", "ababababrr",
      "ababababrs", "ababababrt", "ababababru", "ababababrv", "ababababrw",
      "ababababrx", "ababababry", "ababababrz", "ababababsa", "ababababsb",
      "ababababsc", "ababababsd", "ababababse", "ababababsf", "ababababsg",
      "ababababsh", "ababababsi", "ababababsj", "ababababsk", "ababababsl",
      "ababababsm", "ababababsn", "ababababso", "ababababsp", "ababababsq",
      "ababababsr", "ababababss", "ababababst", "ababababsu", "ababababsv",
      "ababababsw", "ababababsx", "ababababsy", "ababababsz", "ababababta",
      "ababababtb", "ababababtc", "ababababtd", "ababababte", "ababababtf",
      "ababababtg", "ababababth", "ababababti", "ababababtj", "ababababtk",
      "ababababtl", "ababababtm", "ababababtn", "ababababto", "ababababtp",
      "ababababtq", "ababababtr", "ababababts", "ababababtt", "ababababtu",
      "ababababtv", "ababababtw", "ababababtx", "ababababty", "ababababtz",
      "ababababua", "ababababub", "ababababuc", "ababababud", "ababababue",
      "ababababuf", "ababababug", "ababababuh", "ababababui", "ababababuj",
      "ababababuk", "ababababul", "ababababum", "ababababun", "ababababuo",
      "ababababup", "ababababuq", "ababababur", "ababababus", "ababababut",
      "ababababuu", "ababababuv", "ababababuw", "ababababux", "ababababuy",
      "ababababuz", "ababababva", "ababababvb", "ababababvc", "ababababvd",
      "ababababve", "ababababvf", "ababababvg", "ababababvh", "ababababvi",
      "ababababvj", "ababababvk", "ababababvl", "ababababvm", "ababababvn",
      "ababababvo", "ababababvp", "ababababvq", "ababababvr", "ababababvs",
      "ababababvt", "ababababvu", "ababababvv", "ababababvw", "ababababvx",
      "ababababvy", "ababababvz", "ababababwa", "ababababwb", "ababababwc",
      "ababababwd", "ababababwe", "ababababwf", "ababababwg", "ababababwh",
      "ababababwi", "ababababwj", "ababababwk", "ababababwl", "ababababwm",
      "ababababwn", "ababababwo", "ababababwp", "ababababwq", "ababababwr",
      "ababababws", "ababababwt", "ababababwu", "ababababwv", "ababababww",
      "ababababwx", "ababababwy", "ababababwz", "ababababxa", "ababababxb",
      "ababababxc", "ababababxd", "ababababxe", "ababababxf", "ababababxg",
      "ababababxh", "ababababxi", "ababababxj", "ababababxk", "ababababxl",
      "ababababxm", "ababababxn", "ababababxo", "ababababxp", "ababababxq",
      "ababababxr", "ababababxs", "ababababxt", "ababababxu", "ababababxv",
      "ababababxw", "ababababxx", "ababababxy", "ababababxz", "ababababya",
      "ababababyb", "ababababyc", "ababababyd", "ababababye", "ababababyf",
      "ababababyg", "ababababyh", "ababababyi", "ababababyj", "ababababyk",
      "ababababyl", "ababababym", "ababababyn", "ababababyo", "ababababyp",
      "ababababyq", "ababababyr", "ababababys", "ababababyt", "ababababyu",
      "ababababyv", "ababababyw", "ababababyx", "ababababyy", "ababababyz",
      "ababababza", "ababababzb", "ababababzc", "ababababzd", "ababababze",
      "ababababzf", "ababababzg", "ababababzh", "ababababzi", "ababababzj",
      "ababababzk", "ababababzl", "ababababzm", "ababababzn", "ababababzo",
      "ababababzp", "ababababzq", "ababababzr", "ababababzs", "ababababzt",
      "ababababzu", "ababababzv", "ababababzw", "ababababzx", "ababababzy",
      "ababababzz"};
  // act
  auto res = solution.findWords(board, words);

  // assert
  // BOOST_CHECK_EQUAL("abcdefg", res[0]);
}
#endif  // !CASE_4

#if CASE_5
BOOST_AUTO_TEST_CASE(case5) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<char>> board = {{'b', 'b', 'a', 'a', 'b', 'a'},
                                          {'b', 'b', 'a', 'b', 'a', 'a'},
                                          {'b', 'b', 'b', 'b', 'b', 'b'},
                                          {'a', 'a', 'a', 'b', 'a', 'a'},
                                          {'a', 'b', 'a', 'a', 'b', 'b'}};
  std::vector<std::string> words = {"abbbababaa"};
  // act
  auto res = solution.findWords(board, words);

  // assert
  BOOST_CHECK_EQUAL("abbbababaa", res[0]);
}
#endif  // !CASE_5