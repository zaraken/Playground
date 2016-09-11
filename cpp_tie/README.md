Trying to implement cpp::tie function. Playing with tempaltes.
http://en.cppreference.com/w/cpp/utility/tuple/tie

std::tie allows you to conveniently unpack values from compound types into local vars in one line like so:

  int myint; //
  char mychar; //
  std::tuple<int,float,char> mytuple = std::make_tuple (10, 2.6, 'a');          // packing values into tuple
  std::tie (myint, std::ignore, mychar) = mytuple; // unpacking values
  
How do we implement this?
The tie function must return something that we can assign to. So it must be some kind of struct of references to the passed arguments that implements operator=.
And to make it work for arbitrary types and arbitrary number of arguments we have to use templates.
I ended up with two variants: one using composition (TieN1.h) and one using inheritance (TieN2.h)

Essentially what I've done with both implementations is to make something that mimics tuple. So what looks like tuple and implements operator= ? It's a tuple. And that is actually what std::tie does. It creates another tuple (as the description actually states). So the solution to unpacking values does not really require creating a new type from scratch as I did, but it is a good exercise nontheless.

As a matter of principle if we did not use std::tie, we could instead write something like:

tuple<int&, int&, double&, string&>(a, b, c, d) = make_tuple(1, 2, 3.1, "4");
