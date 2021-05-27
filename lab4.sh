rm pipe_gjc3
make namefulPipeW 
make namefulPipeR
make clean
./namefulPipeW test.txt pipe_gjc3 &
./namefulPipeR a.txt pipe_gjc3 