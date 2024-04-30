#pragma once

#include <common/mirapi.h>
#include <common/vector3D.h>
#include <common/mvector.h>
#include <string>
#include <cstdarg>
#include <memory>
#include <math.h>
#include <protocol/struct/mps_buff.h>
//#include <pathEngine/astar/AStarMap.h>

namespace mir3d
{
	struct sActionState
	{
		int64_t 				target_uid{};				// 타켓의 uid
		int64_t					start_time{};				// 시작 시간
		VECTOR3D				pos{};						// 시작 시 캐릭터 좌표

		float					dec_time{};					// 옵션으로 인한 감소 시간
		float					inc_prob{};					// 옵션으로 인한 확률 증가
		float					big_prob{};					// 대성공 확률 증가
		float					exp_prob{};					// 장인 숙련도 증가 
		float					blackiron_prob{};			// 흑철 증가량

		int32_t					start_level{};				// 시작 시 기술레벨(능력치 추가에 따른)
	};

	struct sTargetInfo
    {
        int64_t     uid;
        float       aggro;

		// sTargetInfo() {}

        // sTargetInfo(int64_t uid_, float aggro_)
        // {
        //     uid = uid_;
        //     aggro = aggro_;
        // }

		void Initialize()
		{
			uid = 0;
			aggro = 0;
		}

		void Release() {}
    };

	struct sContributionInfo
	{
		int64_t			uid = 0;		// uid
		// pbe_drop_owner	type;
		float			first_point = 0;	// 최초 명중
		float			damage_point = 0;	// 누적 데미지
		float			total = 0;
		int				contribution_type = 0;
		//void Initialize()
		//{
		//	uid = 0;
		//	// type = pbe_drop_owner::drop_owner_none;
		//	first_point = 0;
		//	damage_point = 0;
		//	total = 0;
		//}

		void Release() {}
	};


	struct sRecipeInfo
	{
		int32_t id{};
		int32_t count{};
		int32_t total{};
		float value{};
		mpe_make_result result{};

		void Initialize()
		{
			id = 0;
			count = 0;
			total = 0;
			value = 0;
		}

		void Release(){}
	};

	struct sEnchantOption
	{
	public:
		int32_t id = 0;
		int32_t value = 0;

	public:
		inline void Reset()
		{
			id = 0;
			value = 0;
		}
	};

	struct sFieldBossInfo
	{
		int32_t monster_id = 0;
		int64_t spawn_time = 0;
	};

	/*struct sMeridians
	{
		int32_t meridians_id;
		int32_t level;
		mir3d::mVector<int32_t> list_acupoints;

		void Initialize(int32_t acupoints_count)
		{
			meridians_id = 0;
			level = 0;
			list_acupoints.Reserve(acupoints_count);
			for (int32_t i = 0; i < acupoints_count; i++)
			{
				list_acupoints.Push_back(0);
			}
		}

		void Release() 
		{
			meridians_id = 0;
			level = 0;
			for (int32_t i = 0; i < list_acupoints.size(); i++)
			{
				list_acupoints[i] = 0;
			}
		}
	};*/

    struct sMeridian
    {
        int32_t meridians_id{};
        int32_t level{};
        int32_t acupoints[5];
    };

	struct sProfesion
	{
		uint16_t level = 0;
		uint16_t grade = 0;
		int32_t exp = 0;
		uint16_t add_level = 0;

		sProfesion() = default;
		
		void Initialize()
		{
			level = 0;
			grade = 0;
			exp = 0;
			add_level = 0;
		}

		void SetBase()
		{
			level = 1;
			grade = 1;
			exp = 0;
			add_level = 0;
		}

		void Release() {}
	};

	struct sItemCount
	{
		int32_t	item_id{};
		int32_t count{};
		
		sItemCount() = default;
		sItemCount(int32_t item_id_, int32_t count_)
		{
			item_id = item_id_;
			count = count_;
		}
	};

	struct constData
	{
		bool is_float{};
		int32_t value_int{};
		float value_float{};
	};

	struct sStatForce
	{
		int32_t level{};
		int32_t value{};
		int32_t recovery{};
		int32_t damageReduction_abs{};
		int32_t	damageReduction_meridians{};
		//float	damageReduction_cooperation;
	};
	
	struct sGoodsValue
	{
		mpe_good_pos pos;
		int32_t value{};

		sGoodsValue(mpe_good_pos _pos, int32_t _value)
		{
			pos = _pos;
			value = _value;
		}
	};

	struct sAbilityOption
	{
		int32_t ability_id{};
		int32_t type{};
		float value{};

		sAbilityOption(int32_t _ability_id, int32_t _type, float _value)
		{
			ability_id = _ability_id;
			type = _type;
			value = _value;
		}
	};

	struct sAbilityCalcOption
	{
		int32_t id{};
		float value{};

		sAbilityCalcOption() {}

		sAbilityCalcOption(int32_t _id, float _value)
		{
			id = _id;
			value = _value;
		}
	};

	struct sSkillAbilityOption
	{
		int32_t group_id{};
		uint8_t level{};
		uint8_t max_level{};

		sSkillAbilityOption(int32_t _group_id, uint8_t _level, uint8_t _max_level)
		{
			group_id = _group_id;
			level = _level;
			max_level = _max_level;
		}
	};

	struct sEnchantStoneOption
	{
		int32_t tid{};
		int32_t grade{};

		sEnchantStoneOption(int32_t _tid, int32_t _grade)
		{
			tid = _tid;
			grade = _grade;
		}
	};

	// 보물 상자의 위치를 랜덤하게 생성하기 위한 정보
	struct sCreateTreasureBox
	{
		int32_t tid{};					// map_treasure_box_table id
		std::vector<int32_t> index;		// respawn pos
	};

	struct sRewardBox
	{
		int32_t item_id{};
		mpe_good_pos good_pos;
		int32_t value{};
		int32_t upgrade_value{};

		sRewardBox(int32_t _item_id, mpe_good_pos _good_pos, int32_t _value, int32_t _upgrade_value)
		{
			item_id = _item_id;
			good_pos = _good_pos;
			value = _value;
			upgrade_value = _upgrade_value;
		}
	};

	struct sTitlePairID
	{
		int32_t gid;
		int32_t condition_id;

		sTitlePairID(int32_t _gid, int32_t _condition_id)
		{
			gid = _gid;
			condition_id = _condition_id;
		}
	};

	struct sDictionaryCompletCount
	{
		int32_t total_count{};
		int32_t complet_count{};

		sDictionaryCompletCount() {}

		sDictionaryCompletCount(int32_t _total_count, int32_t _complet_count)
		{
			total_count = _total_count;
			complet_count = _complet_count;
		}
	};

	struct sRewardItem
	{
		int32_t main_type{};
		int32_t item_type{};
		int32_t item_id{};
		int32_t count{};

		sRewardItem() {}

		sRewardItem(int32_t _main_type, int32_t _item_type, int32_t _item_id, int32_t _count)
		{
			main_type = _main_type;
			item_type = _item_type;
			item_id = _item_id;
			count = _count;
		}
	};

	struct sUpdateItem
	{
		int64_t iuid{};
		int32_t tid{};
		int32_t index{};
		int32_t update{};
		int32_t total{};

		sUpdateItem() {}

		sUpdateItem(int64_t _iuid, int32_t _tid, int32_t _index, int32_t _update, int32_t _total)
		{
			iuid = _iuid;
			tid = _tid;
			index = _index;
			update = _update;
			total = _total;
		}
	};

	struct sLogMakeItem
	{
		int64_t iuid{};
		int32_t tid{};
		int32_t update{};
		int32_t total{};
		mpe_make_result result{};

		sLogMakeItem() {}
	};

	struct sLogCartInfo 
	{
		int64_t uid{};
		int32_t table_id{};
		mpe_good_pos goods_pos{};
		int32_t goods_update{};
		int32_t add_mileage{};

		sLogCartInfo() {}
	};

	struct sLogSummonInfo
	{
		int32_t table_id{};
		int64_t uid{};
		table::GRADE grade{};
		int32_t update{};
		int32_t total{};

		sLogSummonInfo() {}

		void Set(int32_t _tid, int64_t _uid, table::GRADE _grade, int32_t _update, int32_t _total)
		{
			table_id = _tid;
			uid = _uid;
			grade = _grade;
			update = _update;
			total = _total;
		}
	};

	struct sDicPetValue
	{
		int32_t dic_id{};
		int32_t update{};
		int32_t max_value{};
		int32_t category_id{};

		sDicPetValue() {}

		void Set(int32_t _dic_id, int32_t _update, int32_t _max_value, int32_t _category_id)
		{
			dic_id = _dic_id;
			update = _update;
			max_value = _max_value;
			category_id = _category_id;
		}
	};

	struct sLogUpdateItem
	{
		int64_t iuid{};
		int32_t tid{};
		int32_t index{};
		int32_t update{};
		int32_t total{};
		int32_t weight{};
		int32_t upgrade_value{};

		sLogUpdateItem() {}

		sLogUpdateItem(int64_t _iuid, int32_t _tid, int32_t _index, int32_t _update, int32_t _total, int32_t _weight, int32_t _upgrade_value)
		{
			iuid = _iuid;
			tid = _tid;
			index = _index;
			update = _update;
			total = _total;
			weight = _weight;
			upgrade_value = _upgrade_value;
		}
	};

	struct sDecomposeUse
	{
		int32_t tid{};
		int32_t grade{};
		int32_t total{};
		int32_t update{};
		bool	isAll{};

		sDecomposeUse() {}
	};
}