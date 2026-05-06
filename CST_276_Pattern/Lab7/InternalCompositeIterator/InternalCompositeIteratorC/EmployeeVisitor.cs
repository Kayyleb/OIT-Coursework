using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InternalCompositeIteratorC
{
    public class EmployeeVisitor : IVisitor
    {
        double total = 0; 
        public EmployeeVisitor(CompanyComponent component)
        {
            component.Accept(this); // start traversal
        }

        public void Visit(CompanyComposite composite) {}

        public void Visit(Employee employee)
        {
            Console.WriteLine("[EmployeeVisitor] Employee: " + employee.GetName()); // Do something for each Employee node
            total += employee.Salary;
        }
        public double getSalary()
        {
            return total;
        }
    }
}

