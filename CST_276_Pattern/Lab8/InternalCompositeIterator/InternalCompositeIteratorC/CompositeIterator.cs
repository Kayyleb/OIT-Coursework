using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InternalCompositeIteratorC
{
    public class CompositeIterator : AbstractIterator
    {
        private CompanyComponent root;
        private Stack<AbstractIterator> stack;

        public CompositeIterator(CompanyComponent component)
        {
            root = component; // point to the root
            stack = new Stack<AbstractIterator>(); // create a new stack 
            stack.Push(component.CreateIterator()); // Push the root's iterator onto the stack
        }

        public override void First()
        {
            if (stack.Count == 0) return;
            stack.Peek().First();
        }

        public override CompanyComponent Current()
        {
            if (stack.Count == 0) return null;

            return stack.Peek().Current();
        }

        public override void Next()
        {
            if (stack.Count == 0) return;

            AbstractIterator top = stack.Peek();
            CompanyComponent current = top.Current();

            if (current is CompanyComposite composite) 
            {
                AbstractIterator childIterator = composite.CreateIterator();
                stack.Push(childIterator);
                childIterator.First();
            }
            else
            {
                top.Next();
            }
        }

        public override bool Done()
        {
            if (stack.Count == 0) return true;

            AbstractIterator top = stack.Peek();

            if (top.Done())
            {
                stack.Pop();

                // If there is still something on the stack,
                // move the new top iterator forward and check again
                if (stack.Count > 0)
                {
                    stack.Peek().Next();
                    return Done();
                }
                return true;
            }
            return false;
        }
    }
}
