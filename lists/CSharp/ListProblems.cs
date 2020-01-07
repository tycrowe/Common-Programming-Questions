using System;
using System.Collections.Generic;

namespace CSharp
{
    class Program<T>
    {
        
        /// <summary>
        /// Removes duplicate elements from a linked list of any given type 'T'.
        /// </summary>
        /// <param name="a">The given linked list to remove duplicates from.</param>
        /// <returns>A new linked list containing no duplicate entries.</returns>
        public LinkedList<T> RemoveDupes(LinkedList<T> a)
        {
            LinkedList<T> b = new LinkedList<T>();

            int firstCount = a.Count;
            for (int i = 0; i < firstCount; i++)
            {
                if (!b.Contains(a.First.Value))
                {
                    b.AddLast(a.First.Value);
                }
                a.RemoveFirst();
            }
            
            return b;
        }

        /// <summary>
        /// Helper method, simply prints out a linked list.
        /// </summary>
        /// <param name="a">The given linked list to print out.</param>
        public void PrintList(LinkedList<T> a)
        {
            while (a.First != null)
            {
                Console.Write(a.First.Value + " ");
                a.RemoveFirst();
            }
        }
        
        
    }

    class MainExe
    {
        static void Main(string[] args)
        {
            Program<int> prog = new Program<int>();
            LinkedList<int> listA = new LinkedList<int>(new []{0, 0, 1, 54, 1, 0, 3, 3, 3, 2, 1});
            prog.PrintList(prog.RemoveDupes(listA));
        }
    }
}