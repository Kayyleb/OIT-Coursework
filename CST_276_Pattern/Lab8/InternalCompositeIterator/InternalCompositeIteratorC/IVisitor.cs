using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InternalCompositeIteratorC
{
    public interface IVisitor
    {
        void Visit(CompanyComposite composite);
        void Visit(Employee employee);
    }
}

