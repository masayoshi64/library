---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "start_temp: \u4E00\u56DE\u306E\u9077\u79FB\u3067\u52D5\u304D\u3046\
      \u308B\u30B9\u30B3\u30A2\u5E45\u306E\u6700\u5927\u5024\u7A0B\u5EA6, end_temp:\
      \ \u4E00\u56DE\u306E\u9077\u79FB\u3067\u52D5\u304D\u3046\u308B\u30B9\u30B3\u30A2\
      \u5E45\u306E\u6700\u5C0F\u5024\u7A0B\u5EA6"
    links: []
  bundledCode: "#line 1 \"library/heuristic/annealing.cpp\"\n/**\n * @brief start_temp:\
    \ \u4E00\u56DE\u306E\u9077\u79FB\u3067\u52D5\u304D\u3046\u308B\u30B9\u30B3\u30A2\
    \u5E45\u306E\u6700\u5927\u5024\u7A0B\u5EA6, end_temp: \u4E00\u56DE\u306E\u9077\
    \u79FB\u3067\u52D5\u304D\u3046\u308B\u30B9\u30B3\u30A2\u5E45\u306E\u6700\u5C0F\
    \u5024\u7A0B\u5EA6\n */\n\n// struct State{\n//     double score;\n//     State(){}\n\
    //     void step(){}\n//     void rollback(){}\n//     double get_new_score(){}\n\
    // };\n\ntemplate<typename State>\nState hill_climbing(State state, double time_limit){\n\
    \    Timer timer;\n    timer.start();\n    double time = timer.lap();\n    rep(t,\
    \ 1e9) {\n        if(time > time_limit) break;\n\n        double score = state.score;\n\
    \        double new_score = state.get_new_score(time / time_limit);\n        if\
    \ (new_score >= score) {\n            state.step();\n        }\n        if(t %\
    \ 100 == 0){\n            cerr << t << \": \" << state.score << endl;\n      \
    \      time = timer.lap();\n        }\n    }\n    return state;\n}\n\ntemplate<typename\
    \ State>\nState simulated_annealing(State state, double start_temp, double end_temp,\
    \ double time_limit) {\n    Timer timer;\n    timer.start();\n    double time\
    \ = timer.lap();\n    rep(t, 1e9) {\n        double temp = start_temp + (end_temp\
    \ - start_temp) * time / time_limit;\n        if(time > time_limit) break;\n\n\
    \        double score = state.score;\n        double new_score = state.get_new_score();\n\
    \        double prob = exp((new_score - score) / temp);\n        if (prob > (double)\
    \ xor64(10000000) / 10000000) {\n            state.step();\n        }\n      \
    \  if(t % 100 == 0){\n            cerr << t << \": \" << state.score << endl;\n\
    \            time = timer.lap();\n        }\n    }\n    return best_state;\n}\n"
  code: "/**\n * @brief start_temp: \u4E00\u56DE\u306E\u9077\u79FB\u3067\u52D5\u304D\
    \u3046\u308B\u30B9\u30B3\u30A2\u5E45\u306E\u6700\u5927\u5024\u7A0B\u5EA6, end_temp:\
    \ \u4E00\u56DE\u306E\u9077\u79FB\u3067\u52D5\u304D\u3046\u308B\u30B9\u30B3\u30A2\
    \u5E45\u306E\u6700\u5C0F\u5024\u7A0B\u5EA6\n */\n\n// struct State{\n//     double\
    \ score;\n//     State(){}\n//     void step(){}\n//     void rollback(){}\n//\
    \     double get_new_score(){}\n// };\n\ntemplate<typename State>\nState hill_climbing(State\
    \ state, double time_limit){\n    Timer timer;\n    timer.start();\n    double\
    \ time = timer.lap();\n    rep(t, 1e9) {\n        if(time > time_limit) break;\n\
    \n        double score = state.score;\n        double new_score = state.get_new_score(time\
    \ / time_limit);\n        if (new_score >= score) {\n            state.step();\n\
    \        }\n        if(t % 100 == 0){\n            cerr << t << \": \" << state.score\
    \ << endl;\n            time = timer.lap();\n        }\n    }\n    return state;\n\
    }\n\ntemplate<typename State>\nState simulated_annealing(State state, double start_temp,\
    \ double end_temp, double time_limit) {\n    Timer timer;\n    timer.start();\n\
    \    double time = timer.lap();\n    rep(t, 1e9) {\n        double temp = start_temp\
    \ + (end_temp - start_temp) * time / time_limit;\n        if(time > time_limit)\
    \ break;\n\n        double score = state.score;\n        double new_score = state.get_new_score();\n\
    \        double prob = exp((new_score - score) / temp);\n        if (prob > (double)\
    \ xor64(10000000) / 10000000) {\n            state.step();\n        }\n      \
    \  if(t % 100 == 0){\n            cerr << t << \": \" << state.score << endl;\n\
    \            time = timer.lap();\n        }\n    }\n    return best_state;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/heuristic/annealing.cpp
  requiredBy: []
  timestamp: '2023-10-01 20:18:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/heuristic/annealing.cpp
layout: document
redirect_from:
- /library/library/heuristic/annealing.cpp
- /library/library/heuristic/annealing.cpp.html
title: "start_temp: \u4E00\u56DE\u306E\u9077\u79FB\u3067\u52D5\u304D\u3046\u308B\u30B9\
  \u30B3\u30A2\u5E45\u306E\u6700\u5927\u5024\u7A0B\u5EA6, end_temp: \u4E00\u56DE\u306E\
  \u9077\u79FB\u3067\u52D5\u304D\u3046\u308B\u30B9\u30B3\u30A2\u5E45\u306E\u6700\u5C0F\
  \u5024\u7A0B\u5EA6"
---
