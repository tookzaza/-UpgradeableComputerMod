class CircuitBoard extends Inventory_Base
{
    int m_Tier;

    void CircuitBoard()
    {
        m_Tier = 1; // Default tier 1, can be set on spawn or in config
    }

    void SetTier(int tier)
    {
        m_Tier = tier;
    }

    int GetTier()
    {
        return m_Tier;
    }

    override string GetDisplayName()
    {
        return "Circuit Board Tier " + m_Tier;
    }
}
