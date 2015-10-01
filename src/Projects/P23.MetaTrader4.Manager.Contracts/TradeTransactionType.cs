namespace P23.MetaTrader4.Manager.Contracts
{
    /// <summary>
    /// Trade transaction type
    /// </summary>
    public enum TradeTransactionType : byte
    {
        /// <summary>
        /// Prices requets
        /// </summary>
        PricesGet,
        /// <summary>
        /// Requote
        /// </summary>
        PricesRequote,
        
        /// <summary>
        /// Open order (Instant Execution)
        /// </summary>
        OrderIeOpen = 64,
        /// <summary>
        /// Open order (Request Execution)
        /// </summary>
        OrderReqOpen,
        /// <summary>
        /// Open order (Market Execution)
        /// </summary>
        OrderMkOpen,
        /// <summary>
        /// Open pending order
        /// </summary>
        OrderPendingOpen,
        
        /// <summary>
        /// Close order (Instant Execution)
        /// </summary>
        OrderIeClose,
        /// <summary>
        /// Close order (Request Execution)
        /// </summary>
        OrderReqClose,
        /// <summary>
        /// Close order (Market Execution)
        /// </summary>
        OrderMkClose,

        /// <summary>
        /// Modify pending order
        /// </summary>
        OrderModify,
        /// <summary>
        /// Delete pending order
        /// </summary>
        OrderDelete,
        /// <summary>
        /// Close order by order
        /// </summary>
        OrderCloseBy,
        /// <summary>
        /// Close all orders by symbol
        /// </summary>
        OrderCloseAll,

        /// <summary>
        /// Open order
        /// </summary>
        BrOrderOpen,
        /// <summary>
        /// Close order
        /// </summary>
        BrOrderClose,
        /// <summary>
        /// Delete order (ANY OPEN ORDER!!!)
        /// </summary>
        BrOrderDelete,
        /// <summary>
        /// Close order by order
        /// </summary>
        BrOrderCloseBy,
        /// <summary>
        /// Close all orders by symbol
        /// </summary>
        BrOrderCloseAll,
        /// <summary>
        /// Modify open price, stoploss, takeprofit etc. of order
        /// </summary>
        BrOrderModify,
        /// <summary>
        /// Activate pending order
        /// </summary>
        BrOrderActivate,
        /// <summary>
        /// Modify comment of order
        /// </summary>
        BrOrderComment, 
        /// <summary>
        /// Balance credit
        /// </summary>
        BrBalance
    }
}