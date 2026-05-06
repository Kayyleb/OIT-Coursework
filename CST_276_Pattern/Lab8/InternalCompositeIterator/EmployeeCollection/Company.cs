using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EmployeeCollection
{
    public class Company
    {
        public string Name { get; set; }
        public string Desc { get; set; }
        private List<Employee> Employees = new List<Employee>();

        public Company(string N , string D)
        {
            Name = N;
            Desc = D;
        }

        public void AddEmployee(Employee emp) 
        { 
            Employees.Add(emp); 
        }

        public List<Employee> GetEmployees()
        {
            return Employees;
        }
    }
}
