using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InternalCompositeIteratorC
{
    public class CompanyCompositeVisitor : IVisitor
    {
        public CompanyCompositeVisitor(CompanyComponent component)
        {
            component.Accept(this); // start traversal polymorphically
        }

        public void Visit(CompanyComposite composite)
        {
            Console.WriteLine("[CompanyCompositeVisitor] At company: " + composite.GetName()); // Do something for each CompanyComposite node
        }

        public void Visit(Employee employee) {}
    }
}

