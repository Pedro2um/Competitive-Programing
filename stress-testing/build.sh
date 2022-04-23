g++ -std=c++17 -Wshadow -Wall -o a a.cpp -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG
g++ -std=c++17 -Wshadow -Wall -o brute brute.cpp -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG
g++ -std=c++17 -Wshadow -Wall -o gen gen.cpp -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG