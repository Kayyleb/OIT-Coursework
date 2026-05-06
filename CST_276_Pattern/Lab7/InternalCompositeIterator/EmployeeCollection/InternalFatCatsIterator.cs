using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EmployeeCollection
{
    public class InternalFatCatsIterator : AbstractIterator
    {
        private List<Employee> filtered;
        private int currentIndex;

        public InternalFatCatsIterator(Company company, double threshold)
        {
            filtered = company.GetEmployees().Where(e => e.Salary > threshold).ToList();
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
            return currentIndex >= filtered.Count;
        }

        public override Employee Current()
        {
            return filtered[currentIndex];
        }
    }
}
