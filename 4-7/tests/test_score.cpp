#include <gtest/gtest.h>

extern "C" {
#include "score.h"
}

TEST(T, nofile){
	ScoreBook b = {};
	EXPECT_NE(0, score_load_file("data/nofile.txt", &b));
}
TEST(T, Count){
	ScoreBook b ={};
	ASSERT_EQ(0, score_load_file("data/scores.txt", &b));
	EXPECT_EQ(5, b.count);
}
TEST(T, CountLimit){
	ScoreBook b ={};
	ASSERT_EQ(0, score_load_file("data/scores-equal.txt" , &b));
	EXPECT_EQ(3, score_count_under_limit(&b, 80));
}
TEST(T,Avg){
	ScoreBook b ={};
	ASSERT_EQ(0, score_load_file("data/scores-no-match.txt", &b));
	EXPECT_DOUBLE_EQ(0.0, score_average_under_limit(&b, 80));
}
TEST(T, Sum){
	ScoreBook b = {};
	ASSERT_EQ(0, score_load_file("data/scores.txt", &b));
	EXPECT_EQ(148, score_sum_under_limit(&b, 80));
}

TEST(T, Null){
	EXPECT_EQ(0, score_count_under_limit(NULL, 80));
	EXPECT_EQ(0, score_sum_under_limit(NULL, 80));
	EXPECT_EQ(0, score_max(NULL));
	EXPECT_EQ(0, score_min(NULL));
}
