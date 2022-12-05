
#pragma once
#ifndef __DAY_1_HPP
#define __DAY_1_HPP
#include <advent/lib.hpp>

#include <fstream>
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <numeric>
#include <tuple>
#include <cstdio>

using std::cout;

enum class Hand
{
    ROCK,
    PAPER,
    SCISSORS
};
enum class Strategy
{
    WIN,
    LOSE,
    DRAW
};

class RockPaperScissorsRound
{
public:
    int our_score;
    int their_score;

    RockPaperScissorsRound(bool use_ultra_secret_strategy);

    void play_hand(char opponent_col, char our_col);

private:
    void calculate_score(Hand their_play, Hand our_play);
    Hand choose_hand(Hand their_play, Strategy strategy);

    bool use_ultra_secret_strategy;
    const std::map<char, Hand> convert_play_to_hand{
        {'X', Hand::ROCK},
        {'Y', Hand::PAPER},
        {'Z', Hand::SCISSORS},
        {'A', Hand::ROCK},
        {'B', Hand::PAPER},
        {'C', Hand::SCISSORS},
    };
    const std::map<char, Strategy> convert_play_to_strategy{
        {'X', Strategy::LOSE},
        {'Y', Strategy::DRAW},
        {'Z', Strategy::WIN}};
    const std::map<Strategy, std::map<Hand, Hand>> convert_strategy_to_hand{
        // their play : our play
        {Strategy::WIN, {{Hand::ROCK, Hand::PAPER}, {Hand::PAPER, Hand::SCISSORS}, {Hand::SCISSORS, Hand::ROCK}}},
        {Strategy::LOSE, {{Hand::ROCK, Hand::SCISSORS}, {Hand::PAPER, Hand::ROCK}, {Hand::SCISSORS, Hand::PAPER}}},
    };
    const std::map<Hand, int> convert_hand_to_score{
        {Hand::ROCK, 1},
        {Hand::PAPER, 2},
        {Hand::SCISSORS, 3}};
};

void play_tournament(std::fstream &fs);
bool use_ultra_top_secret_strategy();

#endif