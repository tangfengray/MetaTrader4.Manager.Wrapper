using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace P23.MetaTrader4.Manager.Contracts
{
    public interface IConnectionParameters
    {
        int Login { get; }
        String Server { get;}
        String Password { get;}
    }

    
}
