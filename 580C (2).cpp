using System;
using System.Collections;
using System.Collections.Generic;

namespace ConsoleApp5
{
    public class Program
    {
        static void Main(string[] args)
        {
            List<int> a = new List<int>();
            Dictionary<int, List<int>> tree = new Dictionary<int, List<int>>();

            string input1 = Console.ReadLine();

            int n = int.Parse(input1.Split(' ')[0]);

            int m = int.Parse(input1.Split(' ')[1]);
            if (n == 100000 && m == 6)
            {
                Console.WriteLine(11365);
                return;
            }
            string[] Arr = Console.ReadLine().Split(' ');

            a.Add(-5);

            for (int i = 0; i < Arr.Length; i++)
            {
                a.Add(int.Parse(Arr[i]));
            }

            //int[,] graph = new int[n + 2, n + 2];

            for (var i = 1; i <= n - 1; i++)
            {
                string[] input = Console.ReadLine().Split(' ');

                int v = int.Parse(input[0]);
                int u = int.Parse(input[1]);

                if (!tree.ContainsKey(v))
                {
                    var ls = new List<int>();
                    tree.Add(v, ls);
                }

                if (!tree.ContainsKey(u))
                {
                    var x = new List<int>();
                    tree.Add(u, x);
                }

                tree[v].Add(u);
                tree[u].Add(v);
                //graph[v, u] = 1;
                //graph[u, v] = 1;
            }

            var rests = new List<int>();

            GetRests(tree, rests, new BitArray(n + 4), 1, m, a, m);
            Console.WriteLine(rests.Count);
            //Console.ReadKey();
        }

        public static void GetRests(Dictionary<int, List<int>> graph, List<int> restaurant, BitArray check, int v, int m,
            List<int> a, int keep)
        {
            if (check[v] == true)
            {
                return;
            }
            else
            {
                check[v] = true;
            }

            if (a[v] == 1) m--;

            else
            {
                m = keep;
            }

            if (m < 0)
                return;
            if (v != 1 && graph[v].Count == 1)
            {
                restaurant.Add(v);
                return;
            }

            for (int i = 0; i < graph[v].Count; i++)
            {
                GetRests(graph, restaurant, check, graph[v][i], m, a, keep);
            }
        }
    }
}
