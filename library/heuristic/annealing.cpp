/**
 * @brief start_temp: 一回の遷移で動きうるスコア幅の最大値程度, end_temp: 一回の遷移で動きうるスコア幅の最小値程度
 */

// struct State{
//     double score;
//     State(){}
//     void step(){}
//     void rollback(){}
//     double get_new_score(){}
// };

template<typename State>
State hill_climbing(State state, double time_limit){
    Timer timer;
    timer.start();
    double time = timer.lap();
    rep(t, 1e9) {
        if(time > time_limit) break;

        double score = state.score;
        double new_score = state.get_new_score(time / time_limit);
        if (new_score >= score) {
            state.step();
        }
        if(t % 100 == 0){
            cerr << t << ": " << state.score << endl;
            time = timer.lap();
        }
    }
    return state;
}

template<typename State>
State simulated_annealing(State state, double start_temp, double end_temp, double time_limit) {
    Timer timer;
    timer.start();
    double time = timer.lap();
    rep(t, 1e9) {
        double temp = start_temp + (end_temp - start_temp) * time / time_limit;
        if(time > time_limit) break;

        double score = state.score;
        double new_score = state.get_new_score();
        double prob = exp((new_score - score) / temp);
        if (prob > (double) xor64(10000000) / 10000000) {
            state.step();
        }
        if(t % 100 == 0){
            cerr << t << ": " << state.score << endl;
            time = timer.lap();
        }
    }
    return best_state;
}