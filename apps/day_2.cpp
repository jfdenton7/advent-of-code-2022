#include <day_2.hpp>

int main()
{
    std::fstream fs;
    auto file_name = startup(2);
    auto file_opened = open_file(file_name, fs);
    if (file_opened)
    {
        cout << "starting tournament!\n";
        play_tournament(fs);
    }
    else
    {
        cout << "failed to open file" << std::endl;
        return -1;
    }
    return 0;
}

RockPaperScissorsRound::RockPaperScissorsRound(bool use_ultra_secret_strategy = false)
{
    this->our_score = 0;
    this->their_score = 0;
    this->use_ultra_secret_strategy = use_ultra_secret_strategy;
}

void RockPaperScissorsRound::play_hand(char opponent_col, char our_col)
{
    if (this->use_ultra_secret_strategy)
    {
        auto strategies = this->convert_play_to_strategy;
        auto hands = this->convert_play_to_hand;
        this->calculate_score(
            hands[opponent_col],
            this->choose_hand(hands[opponent_col], strategies[our_col]));
    }
    else
    {
        auto hands = this->convert_play_to_hand;
        this->calculate_score(hands[opponent_col], hands[our_col]);
    }
}

void RockPaperScissorsRound::calculate_score(Hand their_hand, Hand our_hand)
{
    auto scores = this->convert_hand_to_score;
    this->our_score = scores[our_hand];
    this->their_score = scores[their_hand];

    if (our_hand == their_hand)
    {
        this->our_score += 3;
        this->their_score += 3;
    }
    else if (our_hand == Hand::PAPER && their_hand == Hand::ROCK)
    {
        this->our_score += 6;
    }
    else if (our_hand == Hand::SCISSORS && their_hand == Hand::PAPER)
    {
        this->our_score += 6;
    }
    else if (our_hand == Hand::ROCK && their_hand == Hand::SCISSORS)
    {
        this->our_score += 6;
    }
    else
    {
        this->their_score += 6;
    }
}

Hand RockPaperScissorsRound::choose_hand(Hand their_play, Strategy strategy)
{
    if (strategy == Strategy::DRAW)
    {
        return their_play;
    }
    else
    {
        auto strategies = this->convert_strategy_to_hand;
        return strategies[strategy][their_play];
    }
}

void play_tournament(std::fstream &fs)
{
    int their_total_score = 0;
    int our_total_score = 0;
    bool strategy = use_ultra_top_secret_strategy();

    std::string round;
    while (std::getline(fs, round))
    {
        auto rps_round = new RockPaperScissorsRound(strategy);
        rps_round->play_hand(round.front(), round.back());
        our_total_score += rps_round->our_score;
        their_total_score += rps_round->their_score;
        delete rps_round;
    }
    cout << "our score: " << our_total_score << "\n";
    cout << "their score: " << their_total_score << "\n";
}

bool use_ultra_top_secret_strategy()
{
    char answer;
    std::cout << "Do you want to use the ultra top secret strategy? (Y/N): ";
    std::cin >> answer;
    if (answer == 'Y' || answer == 'y')
    {
        return true;
    }
    return false;
}