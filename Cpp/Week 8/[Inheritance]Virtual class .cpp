#include<iostream>
#include<string>
#include <fstream>
using namespace std;

class base
{
    public:
        base() { name = " "; age = 0;}
        void setname(const string str) { name = str; }
        void setage(const int a) { age = a; }
        string getname() const { return name; }
        int getage() const { return age; }

    private:
        string name;
        int age;
};

class leader: virtual public base
{
	public:
		leader(): base() { job = " "; dep = " "; }
		void setjob(const string str) { job = str; }
		void setdep(const string str) { dep = str; }
		string getjob() { return job; }
		string getdep() { return dep; }

	private:
		string job;
		string dep;
};

class engineer: virtual public base
{
	public:
		engineer(): base() { prof = " "; major = " "; }
		void setprof(const string str) { prof = str; }
		void setmajor(const string str) { major = str; }
		string getprof() { return prof; }
		string getmajor() { return major; }

	private:
		string prof;
		string major;
};

class chairman: public leader, public engineer
{
	public:
		chairman(): leader(), engineer() {}
};


int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n;
	cin>>n;
	for (int i=0;i<n;i++)
	{
		string name,job,dep,major,prof;
    	int age;
		cin>>name>>age>>job>>dep>>major>>prof;
		chairman man;
		man.setname(name);
		man.setage(age);
		man.setjob(job);
		man.setdep(dep);
		man.setmajor(major);
		man.setprof(prof);
		
		cout<<"name: "<<man.getname()<<" age: "<<man.getage()<<" dep: "<<man.getdep()
			<<" job: "<<man.getjob()<<endl;
		cout<<"prof: "<<man.getprof()<<" major: "<<man.getmajor()<<endl;
	}
	return 0;
}