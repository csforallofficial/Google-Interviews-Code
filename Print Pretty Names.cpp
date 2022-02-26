class Employee;

class Solution
{
public:
	static void printPrettyNames(vector<Employee*> &employees);

	static void dfsPrint(Employee *emp, int indent);
};

//Creating The Skeleton Of The System.
class Employee
{
   public:
   int id = 0;		//id -> Current Employee's ID.
   int managerID = 0;		//managerID -> Manager's ID Of The Current Employee.
   string name;		//Name Of The Current Employee.
   vector<Employee*> team;		//Team Of (Sub-Ordinates/Other Employees) Under The Current Employee.

   Employee(int id, int managerId, const string &name);		//Creating a Constructor To Initialize The Values Given By The User.

};

void Solution::printPrettyNames(vector<Employee*> &employees)
{
  unordered_map<int, Employee*> idToEmployee;		//Creating A Map To Link an Employee With Other Associated Employees.
  int maxId = -1;		//maxId Will Store The ID Of The Ultimate Manager.

  for (auto e : employees)		//Traversing Through All The Employees.
  {
	  idToEmployee[e->id] = e;		//Linking Employee IDs.

	  if (e->id == e->managerID)		//If The Employee ID Is Same As The Manager ID, Chances Are It Is The Ultimate Manager.
	  {
		 maxId = max(maxId, e->id);		//Keep Track Of The Ultimate Manager.
	  }

	  else		//If The Employee ID Is Not Same As The Manager ID, We Will Link The Current Employee With It's Manager.
	  {
		  if (idToEmployee.find(e->managerID) != idToEmployee.end())
		  {
			  idToEmployee[e->managerID]->team.push_back(e);		//Pushing The Employee Into It's Manager's Team.
		  }
	  }
  }

  Employee *highest = idToEmployee[maxId];		//*highest Will Be Pointing To The Ultimate Manager.
  dfsPrint(highest,0);		//Calling A Recursive Function To Print The Ultimate Manager And It's Sub-Ordinates In A Hierarchy, With An Indentation For Better Look.


}

void Solution::dfsPrint(Employee *emp, int indent)
{
	if (emp == nullptr)		//If emp is Pointing To A nullptr i.e, If No Employee Exist In A Parent Employee's Team, Just Return.
	{
	   return;
	}

	cout << emp->name.indent(indent) << std::endl;		//Else, Print The Current Employee's Name With An Indentation.

	for (auto e : *emp->team)		//Traverse Through The Current Employee's Team And Again Do A Recrusive Call With An Indentation Of 3 For Better Look.
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
