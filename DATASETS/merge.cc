# include <stdio.h>
# include <math.h>
# include <vector>
using namespace std;
typedef vector<double> Data;
vector<Data> patterns100;
vector<Data> patterns200;
vector<Data> patterns1000;
vector<Data> patterns2000;
vector<Data> patternsX;

double distance(Data &x,Data &y)
{
	double sum=0.0;
	for(int i=0;i<x.size();i++)
		sum+=pow(x[i]-y[i],2.0);
	return sum;
}

int main(int argc,char **argv)
{
	FILE *f1=fopen(argv[1],"r");
	FILE *f2=fopen(argv[2],"r");
	int d1,c1;
	int d2,c2;
	fscanf(f1,"%d",&d1);
	fscanf(f1,"%d",&c1);
	fscanf(f2,"%d",&d2);
	fscanf(f2,"%d",&c2);
	vector<double> x;
	x.resize(d1);
	for(int i=0;i<c1;i++)
	{
		for(int j=0;j<d1;j++)
			fscanf(f1,"%lf",&x[j]);
		double y;
		fscanf(f1,"%lf",&y);
		if(y==100) patterns100.push_back(x);
		else
		if(y==1000) patterns1000.push_back(x);
		else
		if(y==200) patterns200.push_back(x);
		else
		if(y==2000) patterns2000.push_back(x);
	}
	for(int i=0;i<c2;i++)
	{
		for(int j=0;j<d1;j++)
			fscanf(f2,"%lf",&x[j]);
		double y;
		fscanf(f2,"%lf",&y);
		if(y==100) patterns100.push_back(x);
		else
		if(y==1000) patterns1000.push_back(x);
		else
		if(y==200) patterns200.push_back(x);
		else
		if(y==2000) patterns2000.push_back(x);
	}
	fclose(f1);
	fclose(f2);
	for(int i=0;i<patterns1000.size();i++)
	{
		printf("done %d from %d \n",i,patterns1000.size());
		double minDist=1e+100;
		bool pass1=false;
		for(int j=0;j<patterns100.size();j++)
		{
			double d=distance(patterns1000[i],patterns100[j]);
			if(d<minDist) minDist = d;
		}
		if(minDist<1e-4) continue;
		minDist=1e+100;
		for(int j=0;j<patterns200.size();j++)
		{
			double d=distance(patterns1000[i],patterns200[j]);
			if(d<minDist) minDist = d;
		}
		if(minDist<1e-4) continue;
		patternsX.push_back(patterns1000[i]);
	}
	for(int i=0;i<patterns2000.size();i++)
	{
		printf("done %d from %d \n",i,patterns2000.size());
		double minDist=1e+100;
		bool pass1=false;
		for(int j=0;j<patterns100.size();j++)
		{
			double d=distance(patterns2000[i],patterns100[j]);
			if(d<minDist) minDist = d;
		}
		if(minDist<1e-4) continue;
		minDist=1e+100;
		for(int j=0;j<patterns200.size();j++)
		{
			double d=distance(patterns2000[i],patterns200[j]);
			if(d<minDist) minDist = d;
		}
		if(minDist<1e-4) continue;
		patternsX.push_back(patterns2000[i]);
	}
	int finalCount = patterns100.size()+patterns200.size()+patternsX.size();	
	printf("%d\n%d\n",d1,finalCount);
	for(int i=0;i<patterns100.size();i++)
	{
		for(int j=0;j<d1;j++)
			printf("%lf ",patterns100[i][j]);
		printf("0 \n");
	}
	for(int i=0;i<patterns200.size();i++)
	{
		for(int j=0;j<d1;j++)
			printf("%lf ",patterns200[i][j]);
		printf("1 \n");
	}
	for(int i=0;i<patternsX.size();i++)
	{
		for(int j=0;j<d1;j++)
			printf("%lf ",patternsX[i][j]);
		printf("2 \n");
	}
	return 0;
}
