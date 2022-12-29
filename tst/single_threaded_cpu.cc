#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 0
#define CASE_2 0
#define CASE_3 1
#define DEBUG 1

#include "../src/leetcode/single_threaded_cpu.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> tasks{
      {19, 13}, {16, 9},  {21, 10}, {32, 25}, {37, 4},  {49, 24}, {2, 15},
      {38, 41}, {37, 34}, {33, 6},  {45, 4},  {18, 18}, {46, 39}, {12, 24}};
  std::vector<int> expected{6, 1, 2, 9, 4, 10, 0, 11, 5, 13, 3, 8, 12, 7};
  // act
  auto res = solution.getOrder(tasks);

  // assert
  for (int i = 0; i < expected.size(); ++i)
    BOOST_CHECK_EQUAL(expected[i], res[i]);
}
#endif  // !CASE_1

#if CASE_2
BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> tasks{{1, 2}, {2, 4}, {3, 2}, {4, 1}};
  std::vector<int> expected{0, 2, 3, 1};
  // act
  auto res = solution.getOrder(tasks);

  // assert
  for (int i = 0; i < expected.size(); ++i)
    BOOST_CHECK_EQUAL(expected[i], res[i]);
}
#endif  // !CASE_1

#if CASE_3
BOOST_AUTO_TEST_CASE(case3) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> tasks{
      {277, 724}, {277, 927}, {277, 27},  {277, 436}, {277, 686}, {277, 495},
      {277, 425}, {858, 101}, {858, 265}, {858, 818}, {858, 626}, {858, 885},
      {858, 387}, {443, 12},  {443, 66},  {443, 999}, {443, 254}, {443, 133},
      {443, 221}, {443, 768}, {443, 567}, {443, 883}, {443, 473}, {617, 197},
      {329, 901}, {329, 373}, {329, 316}, {329, 125}, {329, 703}, {329, 201},
      {329, 382}, {329, 831}, {329, 826}, {329, 494}, {638, 75},  {638, 896},
      {64, 107},  {64, 866},  {64, 882},  {64, 74},   {64, 244},  {64, 441},
      {64, 428},  {64, 667},  {64, 355},  {823, 928}, {823, 425}, {823, 148},
      {823, 558}, {823, 629}, {509, 688}, {509, 771}, {509, 930}, {509, 161},
      {509, 652}, {509, 931}, {509, 960}, {509, 236}, {235, 371}, {235, 157},
      {235, 55},  {235, 259}, {235, 439}, {235, 183}, {235, 724}, {235, 188},
      {235, 375}, {495, 982}, {495, 535}, {495, 451}, {495, 26},  {495, 868},
      {495, 37},  {495, 53},  {858, 814}, {556, 571}, {556, 307}, {556, 274},
      {556, 882}, {556, 986}, {556, 980}, {556, 997}, {556, 481}, {556, 670},
      {605, 207}, {605, 967}, {605, 357}, {605, 520}, {605, 752}, {605, 21},
      {471, 128}, {471, 308}, {471, 947}, {471, 487}, {471, 128}, {471, 494},
      {471, 471}, {958, 377}, {958, 410}, {958, 432}, {958, 252}, {958, 273},
      {958, 491}, {958, 336}, {654, 660}, {654, 210}, {654, 638}, {654, 981},
      {654, 848}, {654, 64},  {654, 639}, {70, 861},  {446, 848}, {446, 383},
      {446, 929}, {446, 810}, {446, 676}, {446, 286}, {446, 134}, {886, 476},
      {886, 316}, {886, 918}, {52, 705},  {52, 592},  {52, 904},  {52, 270},
      {52, 377},  {52, 377},  {52, 309},  {510, 156}, {510, 944}, {510, 710},
      {950, 105}, {911, 382}, {911, 309}, {833, 556}, {833, 204}, {60, 548},
      {60, 892},  {60, 232},  {60, 153},  {60, 362},  {60, 570},  {60, 977},
      {60, 499},  {60, 453},  {60, 314},  {9, 586},   {9, 130},   {9, 642},
      {9, 879},   {298, 614}, {298, 383}, {298, 710}, {530, 542}, {530, 234},
      {530, 2},   {530, 614}, {530, 51},  {530, 822}, {219, 655}, {503, 292},
      {503, 329}, {503, 385}, {503, 643}, {503, 11},  {503, 454}, {503, 739},
      {503, 545}, {511, 527}, {511, 655}, {757, 950}, {757, 484}, {757, 598},
      {757, 470}, {757, 421}, {757, 50},  {161, 731}, {161, 514}, {161, 772},
      {161, 747}, {834, 940}, {834, 772}, {834, 545}, {965, 319}, {965, 858},
      {965, 222}, {965, 700}, {965, 30},  {965, 617}, {965, 872}, {965, 898},
      {691, 930}, {691, 950}, {140, 270}, {140, 246}, {140, 128}, {140, 175},
      {140, 904}, {140, 122}, {140, 931}, {45, 406},  {45, 781},  {45, 986},
      {45, 308},  {880, 745}, {880, 629}, {880, 683}, {880, 672}, {880, 493},
      {359, 867}, {359, 217}, {359, 560}, {359, 943}, {359, 745}, {359, 896},
      {359, 742}, {359, 514}, {522, 908}, {522, 164}, {522, 185}, {522, 611},
      {289, 957}, {289, 155}, {289, 681}, {289, 703}, {884, 453}, {884, 377},
      {884, 109}, {884, 191}, {884, 994}, {884, 115}, {884, 810}, {884, 160},
      {884, 55},  {872, 220}, {872, 25},  {872, 965}, {872, 318}, {872, 695},
      {872, 10},  {772, 190}, {772, 429}, {772, 926}, {772, 962}, {772, 431},
      {772, 844}, {772, 719}, {772, 605}, {772, 571}, {772, 84},  {762, 783},
      {762, 962}, {762, 703}, {762, 978}, {762, 547}, {762, 950}, {762, 653},
      {380, 239}, {380, 155}, {380, 732}, {225, 852}, {225, 94},  {225, 998},
      {225, 471}, {225, 747}, {225, 182}, {225, 196}, {225, 343}, {225, 375},
      {860, 589}, {860, 58},  {860, 976}, {860, 616}, {860, 663}, {860, 347},
      {711, 375}, {711, 418}, {711, 982}, {711, 872}, {259, 577}, {259, 129},
      {259, 995}, {128, 314}, {128, 965}, {128, 203}, {128, 857}, {128, 37},
      {128, 439}, {907, 93},  {907, 177}, {907, 115}, {907, 232}, {907, 727},
      {907, 503}, {907, 786}, {907, 641}, {736, 757}, {736, 946}, {736, 231},
      {736, 975}, {736, 348}, {736, 142}, {736, 967}, {177, 824}, {177, 816},
      {177, 296}, {177, 333}, {177, 323}, {177, 239}, {530, 617}, {530, 856},
      {530, 263}, {181, 785}, {181, 444}, {181, 548}, {181, 951}, {181, 877},
      {181, 838}, {181, 822}, {181, 990}, {181, 368}, {469, 348}, {469, 791},
      {469, 812}, {469, 39},  {469, 46},  {469, 808}, {469, 901}, {469, 674},
      {469, 623}, {469, 937}, {680, 699}, {680, 637}, {680, 550}, {26, 828},
      {26, 365},  {530, 486}, {530, 854}, {530, 160}, {530, 290}, {530, 925},
      {530, 950}, {530, 62},  {530, 329}, {415, 827}, {415, 829}, {415, 616},
      {415, 138}, {415, 742}, {415, 385}, {415, 620}, {415, 831}, {130, 199},
      {130, 830}, {130, 121}, {130, 345}, {130, 846}, {130, 439}, {388, 485},
      {388, 970}, {388, 22},  {388, 530}, {388, 572}, {388, 939}, {388, 824},
      {388, 24},  {388, 17},  {429, 978}, {429, 621}, {429, 19},  {429, 167},
      {429, 611}, {351, 315}, {351, 991}, {351, 329}, {351, 230}, {351, 690},
      {351, 135}, {351, 256}, {351, 932}, {351, 589}, {394, 735}, {394, 630},
      {394, 437}, {394, 605}, {394, 928}, {72, 761},  {72, 652},  {72, 812},
      {72, 416},  {72, 249},  {72, 149},  {234, 897}, {234, 406}, {234, 937},
      {234, 72},  {234, 502}, {234, 949}, {784, 133}, {218, 982}, {787, 820},
      {787, 557}, {707, 837}, {719, 96},  {719, 196}, {719, 373}, {95, 331},
      {95, 757},  {95, 856},  {95, 112},  {95, 552},  {95, 387},  {95, 588},
      {355, 11},  {355, 287}, {527, 277}, {527, 80},  {527, 768}, {527, 478},
      {527, 690}, {527, 876}, {527, 367}, {527, 597}, {36, 701},  {36, 935},
      {36, 110},  {36, 986},  {170, 158}, {170, 544}, {170, 727}, {170, 106},
      {170, 607}, {170, 54},  {170, 543}, {170, 518}, {170, 142}, {590, 523},
      {590, 235}, {590, 377}, {590, 508}, {555, 126}, {555, 510}, {555, 468},
      {493, 714}, {493, 516}, {493, 934}, {493, 833}, {493, 69},  {493, 233},
      {493, 31},  {493, 661}, {493, 293}, {493, 732}, {717, 340}, {106, 599},
      {106, 590}, {106, 262}, {106, 272}, {325, 268}, {325, 438}, {325, 801},
      {325, 27},  {325, 247}, {325, 702}, {325, 526}, {325, 352}, {325, 808},
      {627, 61},  {627, 861}, {627, 249}, {627, 619}, {627, 363}, {627, 205},
      {627, 545}, {627, 296}, {955, 239}, {955, 731}, {999, 213}, {999, 776},
      {999, 395}, {999, 837}, {999, 936}, {999, 791}, {999, 371}, {999, 845},
      {999, 199}, {999, 362}, {4, 476},   {4, 616},   {4, 874},   {4, 76},
      {4, 859},   {948, 829}, {948, 38},  {559, 682}, {559, 715}, {559, 251},
      {559, 588}, {559, 980}, {559, 209}, {559, 508}, {559, 128}, {47, 616},
      {47, 686},  {47, 313},  {114, 284}, {114, 585}, {114, 475}, {114, 850},
      {114, 836}, {114, 561}, {114, 216}, {114, 821}, {114, 335}, {766, 539},
      {947, 253}, {947, 743}, {947, 207}, {947, 841}, {947, 982}, {947, 560},
      {947, 613}, {947, 748}, {14, 704},  {14, 716},  {14, 263},  {14, 633},
      {14, 876},  {14, 24},   {70, 323},  {454, 992}, {454, 982}, {914, 218},
      {339, 479}, {339, 436}, {339, 966}, {339, 711}, {684, 935}, {684, 753},
      {684, 841}, {684, 104}, {684, 131}, {684, 125}, {684, 555}, {684, 964},
      {293, 90},  {730, 798}, {730, 925}, {730, 697}, {730, 625}, {26, 386},
      {26, 41},   {26, 337},  {26, 265},  {26, 821},  {26, 648},  {26, 541},
      {26, 221},  {26, 984},  {906, 90},  {906, 856}, {906, 428}, {171, 540},
      {171, 553}, {171, 170}, {171, 144}, {171, 338}, {171, 686}, {680, 81},
      {680, 498}, {680, 269}, {680, 714}, {680, 9},   {680, 817}, {680, 709},
      {680, 984}, {680, 390}, {893, 122}, {893, 225}, {893, 960}, {893, 787},
      {893, 747}, {893, 831}, {893, 569}, {893, 168}, {893, 131}, {981, 981},
      {981, 3},   {981, 232}, {981, 987}, {981, 678}, {394, 315}, {394, 579},
      {394, 522}, {394, 576}, {394, 5},   {394, 581}, {773, 179}, {773, 645},
      {773, 437}, {773, 141}, {773, 989}, {773, 587}, {773, 744}, {863, 508},
      {863, 6},   {863, 663}, {1, 945},   {1, 192},   {1, 476},   {1, 692},
      {1, 594},   {1, 782},   {1, 427},   {922, 310}, {922, 800}, {922, 371},
      {922, 770}, {922, 976}, {922, 629}, {922, 996}, {922, 682}, {922, 251},
      {922, 219}, {456, 381}, {456, 780}, {456, 291}, {456, 249}, {456, 45},
      {456, 857}, {282, 842}, {282, 632}, {456, 694}, {456, 92},  {456, 284},
      {456, 746}, {702, 237}, {702, 125}, {702, 119}, {702, 354}, {702, 455},
      {702, 972}, {702, 496}, {702, 326}, {321, 379}, {321, 803}, {321, 689},
      {321, 505}, {321, 265}, {321, 802}, {321, 802}, {321, 912}, {321, 102},
      {321, 741}, {170, 771}, {170, 246}, {170, 644}, {170, 759}, {170, 829},
      {170, 421}, {170, 396}, {170, 512}, {170, 929}, {817, 958}, {817, 1000},
      {817, 710}, {817, 546}, {817, 903}, {817, 215}, {181, 618}, {181, 324},
      {181, 807}, {181, 333}, {181, 276}, {181, 67},  {397, 909}, {397, 127},
      {705, 58},  {705, 462}, {705, 341}, {705, 887}, {705, 395}, {705, 227},
      {705, 39},  {705, 791}, {705, 391}, {516, 436}, {516, 425}, {516, 723},
      {516, 586}, {981, 643}, {981, 797}, {981, 5},   {981, 698}, {981, 505},
      {981, 277}, {981, 147}, {981, 507}, {108, 773}, {108, 258}, {108, 206},
      {108, 401}, {108, 435}, {108, 873}, {108, 980}, {108, 481}, {108, 821},
      {890, 667}, {890, 962}, {890, 766}, {890, 627}, {890, 724}, {890, 449},
      {890, 109}, {330, 793}, {330, 357}, {651, 283}, {651, 685}, {651, 471},
      {651, 867}, {651, 799}, {651, 649}, {651, 569}, {651, 755}, {821, 327},
      {821, 590}, {821, 192}, {821, 207}, {821, 836}, {821, 584}, {821, 814},
      {821, 906}, {821, 600}, {961, 888}, {961, 501}, {961, 646}, {961, 62},
      {961, 857}, {845, 631}, {845, 228}, {845, 344}, {845, 87},  {845, 467},
      {845, 667}, {845, 991}, {845, 598}, {845, 348}, {845, 321}, {435, 918},
      {435, 404}, {435, 933}, {435, 839}, {435, 327}, {435, 876}, {435, 501},
      {435, 379}, {435, 606}, {435, 568}, {244, 976}, {244, 124}, {244, 730},
      {244, 545}, {244, 161}, {244, 772}, {244, 831}, {244, 245}, {244, 973},
      {244, 100}, {837, 12},  {837, 828}, {837, 135}, {837, 276}, {837, 600},
      {837, 875}, {236, 305}, {745, 841}, {527, 983}, {527, 992}, {878, 908},
      {878, 328}, {878, 69},  {878, 498}, {878, 283}, {878, 764}, {878, 624},
      {878, 213}, {848, 929}, {43, 721},  {43, 598},  {43, 26},   {208, 780},
      {638, 335}, {638, 88},  {638, 314}, {638, 965}, {638, 258}, {638, 527},
      {140, 859}, {140, 12},  {140, 401}, {140, 176}, {140, 476}, {140, 111},
      {918, 181}, {323, 134}, {323, 157}, {323, 536}, {323, 867}, {431, 413},
      {431, 392}, {431, 480}, {431, 385}, {431, 444}, {431, 222}, {431, 461},
      {431, 809}, {335, 633}, {335, 513}, {335, 252}, {335, 481}, {335, 550},
      {335, 59},  {335, 951}, {335, 847}, {335, 875}, {335, 846}, {408, 50},
      {408, 753}, {408, 185}, {408, 225}, {408, 960}, {408, 983}, {408, 713},
      {408, 212}, {444, 322}, {444, 850}, {444, 815}, {444, 720}, {444, 676},
      {444, 650}, {371, 578}, {371, 372}, {371, 726}, {371, 418}, {371, 692},
      {371, 602}, {371, 209}, {371, 448}, {371, 804}, {371, 189}};
  std::vector<int> expected{6, 1, 2, 9, 4, 10, 0, 11, 5, 13, 3, 8, 12, 7};
  // act
  auto res = solution.getOrder(tasks);

  // assert
  for (int i = 0; i < expected.size(); ++i)
    BOOST_CHECK_EQUAL(expected[i], res[i]);
}
#endif  // !CASE_3