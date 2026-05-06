using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EmployeeCollection
{
    public class InternalReturnAllIterator : AbstractIterator
    {
        private List<Employee> employees;
        private int currentIndex;

        public InternalReturnAllIterator(Company company)
        {
            employees = company.GetEmployees();
            currentIndex = 0;
        }

        public override void First()
        {
            currentIndex = 0;
        }

        public override void Next()
        {
            currentIndex++;
        }

        public override bool Done()
        {
            return currentIndex >= employees.Count;
        }

        public override Employee Current()
        {
            return employees[currentIndex];
        }
    }
}
