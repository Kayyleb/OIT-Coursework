using System;
using EmployeeCollection;          // Part 1
using InternalCompositeIteratorC;  // Part 2

namespace InternalCompositeIterator
{
    internal class Program
    {
        static void Main(string[] args)
        {
            // ================= PART 1 =================
            Company myCompany = new Company("Basic Tech Company", "Software Development Team");

            // Use the Employee from EmployeeCollection (Part 1)
            myCompany.AddEmployee(new EmployeeCollection.Employee("Robert", "111-11-1111", 70000));
            myCompany.AddEmployee(new EmployeeCollection.Employee("Bobby", "222-22-2222", 95000));
            myCompany.AddEmployee(new EmployeeCollection.Employee("Logan", "333-33-3333", 50000));
            myCompany.AddEmployee(new EmployeeCollection.Employee("Diana", "444-44-4444", 120000));

            Console.WriteLine("=== All Employees (Part 1) ===");

            // Fully qualify iterator types to avoid ambiguity
            EmployeeCollection.AbstractIterator allIter =
                new EmployeeCollection.InternalReturnAllIterator(myCompany);

            for (allIter.First(); !allIter.Done(); allIter.Next())
            {
                allIter.Current().DisplayEmployee();
            }

            Console.WriteLine("\n=== Fat Cats (Salary > 80,000) (Part 1) ===");

            EmployeeCollection.AbstractIterator fatIter =
                new EmployeeCollection.InternalFatCatsIterator(myCompany, 80000);

            for (fatIter.First(); !fatIter.Done(); fatIter.Next())
            {
                fatIter.Current().DisplayEmployee();
            }

            // ================= PART 2 =================
            Console.WriteLine("\n================ PART 2 ================\n");

            // Composite company structure (Part 2)
            CompanyComposite mainCompany =
                new CompanyComposite("Basic Tech Companny", "Head Office");

            CompanyComposite hr =
                new CompanyComposite("HR", "Human Resources");

            CompanyComposite engineering =
                new CompanyComposite("Engineering", "Software Engineers");

            CompanyComposite other =
                new CompanyComposite("Janitors", "Cleaning");

            // Use the Employee from InternalCompositeIteratorC (Part 2)
            hr.Add(new InternalCompositeIteratorC.Employee("Alice", "111-11-1111", 70000));
            hr.Add(new InternalCompositeIteratorC.Employee("Bob", "222-22-2222", 95000));

            other.Add(new InternalCompositeIteratorC.Employee("Charlie", "333-33-3333", 30000));
            other.Add(new InternalCompositeIteratorC.Employee("Diana", "444-44-4444", 50000));

            engineering.Add(other);
            engineering.Add(new InternalCompositeIteratorC.Employee("Eve", "555-55-5555", 90000));

            mainCompany.Add(hr);
            mainCompany.Add(engineering);

            // This uses the Part 2 internal iterator via CompanyComposite.CreateIterator()
            mainCompany.Display();

            // This uses the Part 2 internal iterator via CompanyComposite.CreateIterator()
            mainCompany.Display();

            Console.WriteLine("\n=== External Composite Iterator (Part 2) ===\n");

            // EXTERNAL ITERATOR
            CompositeIterator extIter = new CompositeIterator(mainCompany);

            for (extIter.First(); !extIter.Done(); extIter.Next())
            {
                CompanyComponent current = extIter.Current();
                if (current != null)
                {
                    Console.WriteLine(current.GetName());
                }
            }

            Console.WriteLine("\n=== CompanyCompositeVisitor (Part 2) ===\n");

            // VISITOR that reacts only to composites
            new CompanyCompositeVisitor(mainCompany);

            Console.WriteLine("\n=== EmployeeVisitor (Part 2) ===\n");

            // VISITOR that reacts only to employees\
            EmployeeVisitor visited = new EmployeeVisitor(mainCompany);
            Console.WriteLine(visited.getSalary());

            Console.ReadLine();


            Console.ReadLine();
        }
    }
}
