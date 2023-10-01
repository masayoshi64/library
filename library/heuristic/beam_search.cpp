// struct State{
//     double score;
//     vector<State> get_next_states(){}  
//     bool operator<(const State &rhs) const {
//         return score < rhs.score;
//     }
// };

template<typename State>
State greedy_search(State initial_state, int max_turn){
    State state = initial_state;
    rep(t, max_turn){
        auto next_states = state.get_next_states();
        state = *max_element(all(next_states));
    }
    return state;
}

template<typename State>
State beam_search(State initial_state, int max_turn, int beam_width){
    vector<State> beam;
    beam.push_back(initial_state);
    rep(t, max_turn){
        vector<State<T>> next_beam;
        int size = beam.size();
        rep(i, min(beam_width, size)){
            State state = beam[i];
            for(auto next_state: state.get_next_states()){
                next_beam.push_back(next_state);
            }
        }
        sort(rall(next_beam));
        beam = next_beam;
    }
    State best_state = beam[0];
    return best_state;
}

template<typename State>
State chokudai_search(State initial_state, int max_turn, double time_limit, int chokudai_width=1){
    Timer timer;
    vector<priority_queue<S>> beam(max_turn+1);
    beam[0].push(initial_state);
    while(timer.lap() < time_limit){
        rep(t, max_turn){
            rep(i, chokudai_width){
                if(beam[t].empty()) break;
                State state = beam[t].top();
                beam[t].pop();
                for(auto next_state: state.get_next_states()){
                    beam[t+1].push(next_state);
                }
            }
        }
    }
    State best_state = beam[max_turn].top();
    return best_state;
}