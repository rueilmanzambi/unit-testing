
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "list.h"


template class List<int>;

  TEST_CASE("List elements", "[list]")
  {
    List<int> l;
    for (int i = 0; i < 10; i++)
      l.append(i);

    Cell<int>* it = l.iterator();

    SECTION("Check Constructor and Append")
    {
      int i = 0;
      while (it != NULL)
      {
        CHECK(it->elem == i);
        it = it->next;
        i++;
      }
    }

    SECTION("Check copy constructor")
    {
      List<int> k(l);
      Cell<int>* that = k.iterator();
      while(it->next != NULL)
      {
        that->elem = -1;
        CHECK(it->elem != that->elem);
	it = it->next;
	that = that->next;
      }
    }

    SECTION("Check prepend")
    {
      l.prepend(11);
      Cell<int>* it = l.iterator();
      CHECK(it->elem == 11);
      l.prepend(12);
      Cell<int>* ti = l.iterator();
      CHECK(ti->elem == 12);
    }

    SECTION("Check pop")
    {
      l.pop();
      Cell<int>* it = l.iterator();
      for (int i = 1; i < 10; i++)
      {
        CHECK(it->elem == i);
	it=it->next;
      }
    }

    SECTION("Check head()")
    {
      CHECK(l.head() == (it->elem));
      List<int> k;
      CHECK_THROWS_WITH(k.head(), "empty list");
    }

    SECTION("Check tail()")
    {
      List<int> k;
      for (int i = 1; i < 10; i++)
        k.append(i);
      Cell<int>* that = k.iterator();
      List<int> p = l.tail();
      Cell<int>* ptr = p.iterator();

      while (ptr->next != NULL)
      {
        CHECK(that->elem == ptr->elem);
	ptr = ptr->next;
	that=that->next;
      }

      List<int> q;
      CHECK_THROWS_WITH(q.tail(), "empty list");
    }

    SECTION("Check length")
    {
      CHECK(l.length() == 10);
      List<int> k;
      CHECK(k.length() == 0);
    }

    SECTION("Check empty()")
    {
      CHECK(l.empty() == false);
    }
  }
