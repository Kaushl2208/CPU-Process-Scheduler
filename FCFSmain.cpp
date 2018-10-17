#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int Processes[1000], VM[100];
float Time[1000], S_Time[1000], F_Time[1000];
int NumVM, NumPros;
int i,j,extra;
void Less(int NumPros) {
        int i=0;
        while(i<NumPros) {
                Time[i] = Processes[i]/100.0;
                VM[i] = i+1;
                S_Time[i] = 0.0;
                F_Time[i] = Processes[i]/100.0;
                i++;
        }
}
void Multiple(int NumPros, int NumVM){
        int i=0;
        int j=0;
        while(i<NumPros) {
                Time[i] = Processes[i]/100.0;
                VM[i] = j+1;
                if((i+1)%(NumVM)==0) {
                        j=-1;
                }
                i++;
                j++;
        }
}
void excess(int NumPros) {
        extra = NumPros%NumVM;
        int k = NumPros/NumVM;
        Multiple(NumPros-extra, NumVM);
        int l = 0;
        i = k*NumVM;
        j = 0;
        while(l<extra) {
                Time[i] = Processes[i]/100.0;
                VM[i] = j+1;
                i++;
                l++;
                j++;
        }
}
float Total_Time(){
        float m = 0.0;
        for(int i=0; i<NumPros; i++) {
                m = m+Time[i];
        }
        return m;
}
// Main Function Starts
int main() {
        cout<<"Enter the Number of VM : ";
        cin>>NumVM;
        cout<<"Enter the Number of Processes : ";
        cin>>NumPros;
        for(int i=0; i<NumPros; i++) {
                cout<<"Enter the Job length of Processor "<<i+1<<" :";
                cin>>Processes[i];
        }
        float VMT[NumVM]={};
        if(NumPros<NumVM) {
                Less(NumPros);
                int m = 0;
                while(m<NumVM) {
                        VMT[m] = Time[m];
                        m++;
                }
                cout<<"All Ok!";
        }
        else if(NumPros%NumVM==0) {
                Multiple(NumPros, NumVM);
                int m = 0;
                int n = 0;
                while(n<NumPros) {
                        VMT[m] = VMT[m]+Time[n];
                        n++;
                        m++;
                        if(m==NumVM) {
                                m=0;
                        }
                }
        }
        else{
                excess(NumPros);
                int m = 0;
                int n = 0;
                int extra = NumPros%NumVM;
                cout<<extra;
                while(n<NumPros-extra) {
                        VMT[m] = VMT[m]+Time[n];
                        n++;
                        m++;
                        if(m==NumVM) {
                                m=0;
                        }
                }
                while(n<=NumPros) {
                        VMT[m] = VMT[m] + Time[n];
                        m++;
                        n++;
                }
        }
        for(int i=0; i<NumPros; i++) {
                cout<<"Time : "<<Time[i]<<"  VM : "<<VM[i]<<endl;
        }
        for(int i=0; i<NumVM; i++) {
                cout<<"Time Taken By VM "<<i+1<<" : "<<VMT[i]<<endl;
        }
        cout<<"Total Time : "<<Total_Time()<<endl;
        float Avg =  Total_Time()/NumPros;
        cout<<"Total Average Time : "<<Avg<<endl;
        cout<<"Underload When VM Time is less than : "<<Avg*0.3<<endl;
        cout<<"Balanced When VM Time is between : "<<Avg*0.3<<" to "<<Avg*0.7<<endl;
        cout<<"Overload When VM Time is more than : "<<Avg*0.7<<endl;
}
