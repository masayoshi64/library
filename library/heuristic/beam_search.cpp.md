---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/heuristic/beam_search.cpp\"\n// struct State{\n\
    //     double score;\n//     vector<State> get_next_states(){}  \n//     bool\
    \ operator<(const State &rhs) const {\n//         return score < rhs.score;\n\
    //     }\n// };\n\ntemplate<typename State>\nState greedy_search(State initial_state,\
    \ int max_turn){\n    State state = initial_state;\n    rep(t, max_turn){\n  \
    \      auto next_states = state.get_next_states();\n        state = *max_element(all(next_states));\n\
    \    }\n    return state;\n}\n\ntemplate<typename State>\nState beam_search(State\
    \ initial_state, int max_turn, int beam_width){\n    vector<State> beam;\n   \
    \ beam.push_back(initial_state);\n    rep(t, max_turn){\n        vector<State<T>>\
    \ next_beam;\n        int size = beam.size();\n        rep(i, min(beam_width,\
    \ size)){\n            State state = beam[i];\n            for(auto next_state:\
    \ state.get_next_states()){\n                next_beam.push_back(next_state);\n\
    \            }\n        }\n        sort(rall(next_beam));\n        beam = next_beam;\n\
    \    }\n    State best_state = beam[0];\n    return best_state;\n}\n\ntemplate<typename\
    \ State>\nState chokudai_search(State initial_state, int max_turn, double time_limit,\
    \ int chokudai_width=1){\n    Timer timer;\n    vector<priority_queue<S>> beam(max_turn+1);\n\
    \    beam[0].push(initial_state);\n    while(timer.lap() < time_limit){\n    \
    \    rep(t, max_turn){\n            rep(i, chokudai_width){\n                if(beam[t].empty())\
    \ break;\n                State state = beam[t].top();\n                beam[t].pop();\n\
    \                for(auto next_state: state.get_next_states()){\n            \
    \        beam[t+1].push(next_state);\n                }\n            }\n     \
    \   }\n    }\n    State best_state = beam[max_turn].top();\n    return best_state;\n\
    }\n"
  code: "// struct State{\n//     double score;\n//     vector<State> get_next_states(){}\
    \  \n//     bool operator<(const State &rhs) const {\n//         return score\
    \ < rhs.score;\n//     }\n// };\n\ntemplate<typename State>\nState greedy_search(State\
    \ initial_state, int max_turn){\n    State state = initial_state;\n    rep(t,\
    \ max_turn){\n        auto next_states = state.get_next_states();\n        state\
    \ = *max_element(all(next_states));\n    }\n    return state;\n}\n\ntemplate<typename\
    \ State>\nState beam_search(State initial_state, int max_turn, int beam_width){\n\
    \    vector<State> beam;\n    beam.push_back(initial_state);\n    rep(t, max_turn){\n\
    \        vector<State<T>> next_beam;\n        int size = beam.size();\n      \
    \  rep(i, min(beam_width, size)){\n            State state = beam[i];\n      \
    \      for(auto next_state: state.get_next_states()){\n                next_beam.push_back(next_state);\n\
    \            }\n        }\n        sort(rall(next_beam));\n        beam = next_beam;\n\
    \    }\n    State best_state = beam[0];\n    return best_state;\n}\n\ntemplate<typename\
    \ State>\nState chokudai_search(State initial_state, int max_turn, double time_limit,\
    \ int chokudai_width=1){\n    Timer timer;\n    vector<priority_queue<S>> beam(max_turn+1);\n\
    \    beam[0].push(initial_state);\n    while(timer.lap() < time_limit){\n    \
    \    rep(t, max_turn){\n            rep(i, chokudai_width){\n                if(beam[t].empty())\
    \ break;\n                State state = beam[t].top();\n                beam[t].pop();\n\
    \                for(auto next_state: state.get_next_states()){\n            \
    \        beam[t+1].push(next_state);\n                }\n            }\n     \
    \   }\n    }\n    State best_state = beam[max_turn].top();\n    return best_state;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: library/heuristic/beam_search.cpp
  requiredBy: []
  timestamp: '2023-10-01 20:18:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/heuristic/beam_search.cpp
layout: document
redirect_from:
- /library/library/heuristic/beam_search.cpp
- /library/library/heuristic/beam_search.cpp.html
title: library/heuristic/beam_search.cpp
---
