using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace InternalCompositeIteratorC
{
    public class CompanyComposite : CompanyComponent
    {
        public string Name { get; set; }
        public string Desc { get; set; }
        private List<CompanyComponent> child = new List<CompanyComponent>();

        public CompanyComposite(string N, string D)
        {
            this.Name = N;
            this.Desc = D;
        }

        public override void Add(CompanyComponent c)
        {
            child.Add(c);
        }

        public override void Remove(CompanyComponent c)
        {
            child.Remove(c);
        }

        public override List<CompanyComponent> GetCompanyComponents()
        {
            return child;
        }

        public override string GetName() => Name;

        public override AbstractIterator CreateIterator()
        {
            return new InternalReturnAllIterator(this);
        }

        public override void Display()
        {
            Console.WriteLine($"{Name} — {Desc}");

            AbstractIterator iter = CreateIterator();

            for (iter.First(); !iter.Done(); iter.Next())
            {
                iter.Current().Display();
            }
        }

        public override void Accept(IVisitor visitor)
        {
            visitor.Visit(this);

            AbstractIterator iter = CreateIterator();

            for (iter.First(); !iter.Done(); iter.Next())
            {
                iter.Current().Accept(visitor);
            }
        }
    }
}
