using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OrdersDll
{
    public abstract class OrderDecorator : AbstractOrderBase
    {
        protected readonly AbstractOrderBase inner;

        protected OrderDecorator(AbstractOrderBase inner)
        {
            this.inner = inner;
        }

        public override void AddItem(string productCode, int quantity, double cost, double weight)
            => inner.AddItem(productCode, quantity, cost, weight);

        public override void PrintOrderItems()
            => inner.PrintOrderItems();

        public override double GetTotalCost()
            => inner.GetTotalCost();
    }
}
