typedef struct s_struct t_struct;
struct s_struct
{
  int f_t;
  int s_t;
  int n;
};

int             calc(t_listsp *pathsp, int a_t)
{
  t_struct c;

  /*if (!pathsp)
    debug*/
  calc_f1(pathsp, &c, a_t);
  calc_a(pathsp, &c, a_t);
  if (c.f_t < a_t)
    add(pathsp, (a_t - c.f_t));
  return (pathsp->path_len + pathsp->a - 1);
}

void    calc_f1(t_listsp *pathsp, t_struct *c, int a_t)
{
  t_listsp    *p;

  p = pathsp;
  c->s_t = 0;
  c->n = 1;
  p = p->next;
  while (p)
    {
      c->s_t += p->path_len;
      c->n++;
      p = p->next;
    }
}

void            calc_a(t_listsp *pathsp, t_struct *c, int a_t)
{
  t_listsp *p;
  int      s;
  int      i;

  i = 2;
  s = 0;
  pathsp->a = (a_t - (c->n - 1) * pathsp->path_len + c->s_t) / c->n;
  c->f_t = pathsp->a;
  p = pathsp->next;
  while (i <= c->n)
    {
      if ((p->a = pathsp->path_len + pathsp->a - p->path_len) <= 0)
	{
	  c->s_t = s;
	  c->n = i - 1;
	  while (p)
	    {
	      p->a = 0;
	      p = p->next;
	    }
	  calc_a(pathsp, c, a_t);
	  break;
	}
      c->f_t += p->a;
      s += p->path_len;
      p = p->next;
      i++;
    }
}

void    add(t_listsp *pathsp, int i)
{
  t_listsp *p;

  p = pathsp;
  while (i > 0)
    {
      p->a += 1;
      p = p->next;
      i--;
    }
}
