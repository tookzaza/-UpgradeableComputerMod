class CircuitBoard_UpgradeEntity extends EntityAI
{
    int m_Tier;

    void CircuitBoard_UpgradeEntity()
    {
        m_Tier = 1;
    }

    void SetTier(int tier)
    {
        m_Tier = tier;
    }

    int GetTier()
    {
        return m_Tier;
    }

    int GetAddedSlots()
    {
        switch (m_Tier)
        {
            case 1: return 250;
            case 2: return 500;
            case 3: return 750;
            case 4: return 1000;
            default: return 0;
        }
    }
}
