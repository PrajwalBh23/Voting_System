// countA is no. of votes to Candidate A
// countB is no. of votes to Candidate B
// countC is no. of votes to Candidate C
// countD is no. of votes to Candidate D
// countNOTA is no. of votes for not any candidate
// countA is no. of votes to Candidate A
// countB is no. of votes to Candidate B
// countC is no. of votes to Candidate C
// countD is no. of votes to Candidate D
// countNOTA is no. of votes for not any candidate

#include<fstream>
#include<iostream>
#include <cstdlib>

using namespace std;

class Count{
	protected:
		int countA ,countB ,countC ,countD ,countNOTA;
	public:
		void making_zero()
		{
			countA=countB=countC=countD=countNOTA=0;
		}
};
class Candidate:public Count{
	protected:
		int cand;
	public:
		void get_Candidate();
		void calculate();
};
void Candidate::get_Candidate(){
	cout<<"\n\n ### Please Enter your Candidate ###\n\n";
	cout<<"\n Press - 1.Candidate A\n";
	cout<<"\n Press - 2.Candidate B\n";
	cout<<"\n Press - 3.Candidate C\n";
	cout<<"\n Press - 4.Candidate D\n";
	cout<<"\n Press - 5.NOTA\n";
	cout<<"\n\n Input Your Choice (1 - 4)\t:";
	cin>>cand;

}
void Candidate::calculate(){
	if(cand == 1)
	{
		countA++;
		cout<<"\n Thanks For Vote !!!!\n";
	}
	else if(cand == 2)
	{
		countB++;
		cout<<"\n Thanks For Vote !!!!\n";
	}
	else if(cand == 3)
	{
		countC++;
		cout<<"\n Thanks For Vote !!!!\n";
	}
	else if(cand == 4)
	{
		countD++;
		cout<<"\n Thanks For Vote !!!!\n";
	}
	else if(cand == 5)
	{
		countNOTA++;
		cout<<"\n Thanks For Vote !!!!\n";
	}
	else 
	{
		cout<<"\nEnter the correct input !!\n";
	}
}


class Counting :public Candidate {
	public:
		string display();
};
string Counting:: display(){
	cout<<"Candidate A - "<<countA<<endl;
	cout<<"Candidate B - "<<countB<<endl;
	cout<<"Candidate C - "<<countC<<endl;
	cout<<"Candidate D - "<<countD<<endl;
	cout<<"Spoiled Votes - "<<countNOTA<<endl;
	
	return ("Candidate A - "+ to_string(countA)  + "\nCandidate B - "+ to_string(countB) + "\nCandidate C - "+ to_string(countC) +"\nCandidate D - "+ to_string(countD) +"\nSpoiled Votes - "+ to_string(countNOTA));
	
}

class Lead : public Counting{
	public:
		string lead_disp();
};
string Lead::lead_disp(){
	if(countA>countB)
	{
		if(countA>countC)
		{
			if(countA>countD)
			{
				cout<<"[Canditate A]";
				return "[Canditate A]";
			} 
			else if(countA==countD)
			{
				cout<<"\n There is draw between A & C Candidate\n";
			}
			else
			{
				cout<<"  [Canditate D]";
				return "[Canditate D]";
			}
		}
		else if(countA==countC)
		{
			cout<<"\n There is draw between A & C Candidate\n";
		}
		else
			{
				cout<<"  [Canditate C]";
				return "[Canditate C]";
			}
	}
	else if(countA==countB)
		{
			cout<<"\n There is draw between A & B Candidate\n";
		}
	else
	{
		if(countB>countC)
		{
			if(countB>countD)
			{
				cout<<"  [Canditate B]";
				return "[Canditate B]";
			}
			else if(countB==countD)
			{
				cout<<"\n There is draw between B & C Candidate\n";
			}
			else
			{
				cout<<" [Canditate D]";
				return "[Canditate D]";
			}
		}
		else if(countB==countC)
		{
			cout<<"\n There is draw between B & C Candidate\n";
		}
		else
		{
			cout<<"  [Canditate C]";
			return "[Canditate C]";
		}
	}
}
int main()
{
	ofstream outputFile("Result.txt");
	
	if (!outputFile) 
	{
    	cout << "Failed to open the file." << endl;
    	return 1;
  	}
	  	
	int choice;
	int Key;
	Lead L1;
	L1.making_zero();
	
	do{
	cout<<"\n\n ### Welcome to Election / Voiting 2022  ###\n\n";
	cout<<"\n Press - 1.Cast the Vote\n";
	cout<<"\n Press - 2.Find the Vote count\n";
	cout<<"\n Press - 3.Find leading Canditate\n";
	cout<<"\n Press - 0.Exit\n";
	
	cout<<"\n\n Please enter your choice\t:";
	cin>>choice;

	switch (choice)
		{
			case 1 :{
				L1.get_Candidate();
				L1.calculate();
				system("cls");
				break;
		   }
			case 2:{
				cout<<"\n Enter the password to access\t:";
				cin>>Key;
				if(Key == 12345 )
				{
					cout<<"\n\n #### Voting Statics ####\n\n";
					outputFile <<L1.display()<< endl;
				}
				else
				{
					cout<<"\n Wrong Password !!! \n";	
				}
				break;
			}
			case 3 :{
				cout<<"\n Enter the password to access\t:";
				cin>>Key;
				if(Key == 12345 )
				{
					cout<<"\n\n #### Leading Candidate ####\n\n";
					outputFile <<"\n"+ L1.lead_disp() + "is the winner"<< endl;
				}
				else
				{
					cout<<"\n Wrong Password !!! \n";	
				}
				break;
			}
			case 0 :{
				break;
			}
		}
	}while(choice != 0);
	
  // close the file stream
  outputFile.close();
	
	
	return 0;
}
