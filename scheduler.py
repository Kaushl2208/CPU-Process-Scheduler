import pandas
import csv

nop = int(input("No. of Processes : "))
job_length = [0]*(nop)

for i in range(nop):
    job_length[i] = input("Enter Job Length for Job "+ str(i+1) +" (in MIPS) : ")


processor = [3] # Each Processor with speed 100 MIPS

#For no of iterations
a = int(nop/3)
b = int(nop%3)
c = int(a+1)    #total number of batches to iterate

#initializing list of time taken by each processor to do the tasks.
pro_time1 = [0]*(c)
pro_time2 = [0]*(c)
pro_time3 = [0]*(c)

j = [0,1,2] # using it mathematically later for proper iterations.

if b==0:                          # when total no. of process is a multiple of 3
    for i in range(c):
        pro_time1[i] = float(float(job_length[i+j[0]])/100)
        pro_time2[i] = float(float(job_length[i+j[1]])/100)
        pro_time3[i] = float(float(job_length[i+j[2]])/100)
        j = [x+2 for x in j]
else:
     if b==1:                      # when total no. of process is a (multiple of 3)+1
         for i in range(c-1):
             pro_time1[i] = float(float(job_length[i+j[0]])/100)
             pro_time2[i] = float(float(job_length[i+j[1]])/100)
             pro_time3[i] = float(float(job_length[i+j[2]])/100)
             j = [x+2 for x in j]
         jbl = int(job_length[-1])
         pro_time1[c-1] = jbl/100
     elif b==2:                    # when total no. of process is a (multiple of 3)+2
         for i in range(c-1):
             pro_time1[i] = float(float(job_length[i+j[0]])/100)
             pro_time2[i] = float(float(job_length[i+j[1]])/100)
             pro_time3[i] = float(float(job_length[i+j[2]])/100)
             j = [x+2 for x in j]
         jbl1 = int(job_length[-2])
         pro_time1[c-1] = jbl1/100
         jbl2 = int(job_length[-1])
         pro_time2[c-1] = jbl2/100

total_time = [0]*3*c  # initializing list containing time taken by three processors


# Creating a CSV Format and Saving the data

df = pandas.DataFrame(columns=["Job ID","Job Length","Time","CPU ID"]) # initializing columns

Job_ID = list(range(1,nop+1)) # initializing a list for job IDs

df["Job ID"] = Job_ID
df["Job Length"] = job_length

j,k = 0,0

for i in range(c): # Saving a new list having total time taken by each Processes
    total_time[k] = pro_time1[j]
    total_time[k+1] = pro_time2[j]
    total_time[k+2] = pro_time3[j]
    j = j+1
    k = k+3

df["Time"] = total_time[:nop]
CPU_ID = [1,2,3]*(c)
df["CPU ID"] = CPU_ID[:nop]
print(df)
print("The total time taken by Processor 1 : ",sum(pro_time1)," seconds")
print("The total time taken by Processor 2 : ",sum(pro_time2)," seconds")
print("The total time taken by Processor 3 : ",sum(pro_time3)," seconds")

df.to_csv('scheduler.csv',index=False) # Saving as an exteranl csv file.
