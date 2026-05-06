using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InternalCompositeIteratorC
{
    public abstract class AbstractIterator
    {
        public abstract void First();
        public abstract void Next();
        public abstract bool Done();
        public abstract CompanyComponent Current();
    }
}
