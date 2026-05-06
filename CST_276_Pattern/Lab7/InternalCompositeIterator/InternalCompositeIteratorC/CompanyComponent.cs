using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InternalCompositeIteratorC
{
    public abstract class CompanyComponent
    {
        public virtual void Add(CompanyComponent c)
        {
            throw new NotSupportedException();
        }

        public virtual void Remove(CompanyComponent c)
        {
            throw new NotSupportedException();
        }

        public virtual List<CompanyComponent> GetCompanyComponents()
        {
            throw new NotSupportedException();
        }

        public virtual AbstractIterator CreateIterator()
        {
            throw new NotSupportedException();
        }

        public virtual string GetName()
        {
            throw new NotSupportedException();
        }

        public virtual void Display()
        {
            throw new NotSupportedException();
        }

        public abstract void Accept(IVisitor visitor);

    }
}
