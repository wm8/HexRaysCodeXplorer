#include "VirtualTables.h"
#include "json_includer.h"
#include "ObjectExplorer.h"
std::set<ReconstructableTypeVtable*> virt_tables;
void ParseVTBL()
{
	search_objects(true);
	qstring res;
	for (auto& t : virt_tables)
	{
		res.cat_sprnt("0x%x %s\n", t->vtable_address, t->name.c_str());
		if(t->ownMembers.size())
			res.cat_sprnt("ownMembers:\n");
		for (auto& m_info : t->ownMembers)
		{
			auto member = m_info.second;
			res.cat_sprnt("\t0x%x: %s - 0x%x\n", member->offset, member->name.c_str(), member->ea);
		}
		if (t->derivedMembers.size())
			res.cat_sprnt("derivedMembers:\n");
		for (auto& m_info : t->derivedMembers)
		{
			auto member = m_info.second;
			res.cat_sprnt("\t0x%x: %s - 0x%x\n", member->offset, member->name.c_str(), member->ea);
		}
		if (t->parentTypes.size())
			res.cat_sprnt("parentTypes:\n");
		for (auto& p : t->parentTypes)
			res.cat_sprnt("\t%s - 0x%x\n", p->name.c_str(), p->ea);
		if (t->childrenTypes.size())
			res.cat_sprnt("childrenTypes:\n");
		for (auto& c : t->childrenTypes)
			res.cat_sprnt("\t%s - 0x%x\n", c->name.c_str(), c->ea);
		res.cat_sprnt("\n");
	}
	msg("%s", res.c_str());
}