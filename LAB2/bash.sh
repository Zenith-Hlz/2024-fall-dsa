make

# Loop through input files from 01.in to 10.in  
for i in $(seq -w 1 10); do  
    # Execute the program with input file and redirect output to the corresponding .out file  
    ./main < input/$i.in > output/$i.out  
done