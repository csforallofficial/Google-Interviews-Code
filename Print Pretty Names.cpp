class Employee;

class Solution
{
public:
	static void printPrettyNames(vector<Employee*> &employees);

	static void dfsPrint(Employee *emp, int indent);
};

class Employee
{
   public:
   int id = 0;
   int managerID = 0;
   string name;
   vector<Employee*> team;

   Employee(int id, int managerId, const string &name);

};

void Solution::printPrettyNames(vector<Employee*> &employees)
{
  unordered_map<int, Employee*> idToEmployee;
  int maxId = -1;

  for (auto e : employees)
  {
	  idToEmployee[e->id] = e;

	  if (e->id == e->managerID)
	  {
		 maxId = max(maxId, e->id);
	  }

	  if (e->id != e->managerID)
	  {
		  if (idToEmployee.find(e->managerID) != idToEmployee.end())
		  {
			  idToEmployee[e->managerID]->team.push_back(e);
		  }
	  }
  }

  Employee *highest = idToEmployee[maxId];
  dfsPrint(highest,0);


}

void Solution::dfsPrint(Employee *emp, int indent)
{
	if (emp == nullptr)
	{
	   return;
	}

	cout << emp->name.indent(indent) << std::endl;

	for (auto e : *emp->team)
	{
			dfsPrint(e,indent + 3);
	}

}

Employee::Employee(int id, int managerId, const string &name)
{
	this->id = id;
	this->managerID = managerId;
	this->name = name;
	team = vector<Employee>();

}
