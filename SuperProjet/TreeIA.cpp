#include "Tree.h"

namespace BT
{
    IComponentNode::IComponentNode(CompositeNode* parent)
        : m_parent(nullptr)
    {
        setParent(parent);
    }

    IComponentNode::~IComponentNode()
    {
        setParent(nullptr);
    }

    void IComponentNode::setParent(CompositeNode* newParent)
    {
        if (m_parent)
            m_parent->remove(this);

        m_parent = newParent;

        if (m_parent)
            m_parent->add(this);
    }
}

void Game::findValidTarget()
{
    for (auto& enemy : m_bosses)
    {
        if (enemy->getVie() > 0)
        {
            currentboss = enemy;
            return;
        }
    }

    currentboss = nullptr;
}

