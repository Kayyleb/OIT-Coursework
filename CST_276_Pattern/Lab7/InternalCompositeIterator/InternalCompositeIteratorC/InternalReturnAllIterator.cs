using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InternalCompositeIteratorC
{
    public class InternalReturnAllIterator : AbstractIterator
    {
        private List<CompanyComponent> list;
        private int currentIndex;

        public InternalReturnAllIterator(CompanyComposite comp)
        {
            list = comp.GetCompanyComponents();
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
            return currentIndex >= list.Count;
        }

        public override CompanyComponent Current()
        {
            return list[currentIndex];
        }
    }
}
