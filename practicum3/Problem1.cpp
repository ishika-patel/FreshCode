For the given class code given below, create the associated class definition. 
Our test cases already have the code below, we just need the correct definition (the information placed in a .h file).
Company::Company()
{
   companyName = "Google";
}

Company::Company(string name)
{
   companyName= name;
}


bool Company::AddEmployee(string name, int salary)     
{
   if (EmployeeNames.size() < 1024)
   {
      EmployeeNames.push_back(name);
      EmployeeSalary.push_back(salary);
      return true;
   }

   return false;
}
double Company::CalcAvgSalaries()
{  
   int sum=0;
   for (int i=0 ; i < EmployeeSalary.size() ; i++) 
   {
      sum += EmployeeSalary[i]; 
   }

   if (EmployeeSalary.size() > 0)
      return (sum / (double)EmployeeSalary.size());
   else
      return 0;
}

int Company::getMaxSalary()
{   
   int max=0; 
   for (int i=0 ; i < EmployeeSalary.size() ; i++) 
      if (EmployeeSalary[i] >= max) 
         max = EmployeeSalary[i];

   return max;
}

int Company::CountSameNames(string name)
{   
   int count=0; 

   for (int i=0 ; i < EmployeeNames.size() ; i++) 
      if (EmployeeNames[i] == name) 
         count++;

   return count;
   
   // ANSWER
   
   class Company {
    private:
        string companyName;
        int salary;
        vector<string> EmployeeNames;
        vector<int> EmployeeSalary;
    public:
        // default constructor
        Company();
        //parametrized constructor        
        Company(string name);
        
        //void EmployeeNames(string name);
        
        //void EmployeeSalaries(int salary);

        bool AddEmployee(string name, int salary);
        
        double CalcAvgSalaries();
        
        int getMaxSalary();
        
        int CountSameNames(string name);
};