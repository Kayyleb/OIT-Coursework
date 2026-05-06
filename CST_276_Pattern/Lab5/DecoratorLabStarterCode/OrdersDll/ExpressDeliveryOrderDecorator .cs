using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OrdersDll
{
    public class ExpressDeliveryOrderDecorator : OrderDecorator
    {
        public ExpressDeliveryOrderDecorator(AbstractOrderBase inner) : base(inner) { }

        public override double GetTotalCost()
            => inner.GetTotalCost() + 4.00;

        public override void PrintOrderItems()
        {
            Console.WriteLine("A Shipping Cost May Apply");
            base.PrintOrderItems();
            Console.WriteLine("Grand Total with Shipping {0:C}", GetTotalCost());
            Console.WriteLine();
        }
    }
}
