        public static string LinkedListSubtract(Node a, Node b)
        {
            StringBuilder str = new StringBuilder();
            var carry = 0;
            while (a != null && b != null)
            {
                if (a.data > b.data)
                {
                    str.Insert(0, (a.data - b.data - carry));
                    carry = 0;
                }
                else if (a.data == b.data)
                    if (carry > 0)
                        str.Insert(0, (a.data - b.data + 10 - carry));
                    else
                        str.Insert(0, (a.data - b.data));
                else
                {
                    str.Insert(0, (a.data + 10 - b.data - carry));
                    carry = 1;
                }
                
                a = a.next;
                b = b.next;
            }
            return str.ToString();
