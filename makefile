all:
					g++ partition.cpp -o partition
input:
					g++ -std=c++11 -stdlib=libc++ input_creator.cpp -o input_creator
test:
					g++ -std=c++11 -stdlib=libc++ task_4.cpp -o task_4
