using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OrdersDll
{
    public class AmexFeeOrderDecorator : OrderDecorator
    {
        public AmexFeeOrderDecorator(AbstractOrderBase inner) : base(inner) { }

        public override double GetTotalCost() => inner.GetTotalCost() + 5.00;

        public override void PrintOrderItems()
        {
            Console.WriteLine("Payment Method: American Express (+$5.00 processing)");
            base.PrintOrderItems();
            Console.WriteLine("Grand Total with AmEx Fee {0:C}", GetTotalCost());
            Console.WriteLine();
        }
    }

    /*
           OrderDecorator class will forward all calls to inner with no changes
    
        Q: Why is the OrderDecorator c’tor protected?
        A: The OrderDecorator ctor is protected in order to prevent any other decorator from using it because we only want the concrete decorators
           to use the order decorator. This prevents a meaningless base decorator to be created.

     */
}
