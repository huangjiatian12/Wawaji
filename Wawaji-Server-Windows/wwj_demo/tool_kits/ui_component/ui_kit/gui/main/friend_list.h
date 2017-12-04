#pragma once

#include "shared/list_item_util.h"
#include "module/service/photo_service.h"

namespace nim_comp
{
/** @class FriendListItemManager
  * @brief ������һЩ������б�����ص��¼�
  * @copyright (c) 2015, NetEase Inc. All rights reserved
  * @author towik
  * @date 2015/1/1
  */
class FriendList : public nbase::SupportWeakCallback
{
public:
	/**
	* ���캯��
	* @param[in] friend_list ��Ϊ�����б���TreeView�ؼ�ָ��
	*/
	FriendList(ui::TreeView* friend_list);
	virtual ~FriendList();

	/**
	* ��ȡ��Ϊ�����б���TreeView�ؼ�ָ��
	* @return ui::TreeView*	��Ϊ�����б���TreeView�ؼ�ָ��
	*/
	ui::TreeView* GetFriendList() { return friend_list_; }

	/**
	* ��Ӧ��ȡ�����б��Ļص�����
	* @param[in] uinfos ������Ƭ�б�
	* @return void	�޷���ֵ
	*/
	void OnGetFriendList(const std::list<nim::UserNameCard> &user);

private:
	/**
	* ����һ�������б���
	* @param[in] accid �û�id
	* @return void	�޷���ֵ
	*/
	void AddListItem(const std::string& accid);

	/**
	* ����һ�������б��ָ���ķ�����
	* @param[in] accid �û�id
	* @param[in] tree_node ����ؼ�ָ��
	* @return void	�޷���ֵ
	*/
	void AddListItemInGroup(const std::string& accid, ui::TreeNode* tree_node);

	/**
	* ɾ��һ�������б���
	* @param[in] accid �û�id
	* @return void	�޷���ֵ
	*/
	void DeleteListItem(const std::string& accid);

	/**
	* ��ָ���ķ������Ƴ�һ�������б���
	* @param[in] accid �û�id
	* @param[in] tree_node ����ؼ�ָ��
	* @return void	�޷���ֵ
	*/
	void DeleteListItemInGroup(const std::string& accid, ui::TreeNode* tree_node);

	/**
	* ����һ�������б���
	* @param[in] accid �û�id
	* @return ui::TreeNode* �����б���ؼ�ָ��
	*/
	ui::TreeNode* FindFriendItem(const std::string& accid);

	/**
	* ���ݷ������ͺͷ����ǩ��ȡ����ؼ�
	* @param[in] groupType ��������
	* @param[in] letter ������װ�
	* @return ui::TreeNode*	����ؼ�
	*/
	ui::TreeNode* GetGroup(GroupType groupType, wchar_t letter = L'');

	/**
	* �ؼ���Χ������ָ���ķ����ǩ
	* @param[in] letter �����ǩ��A��Z
	* @return void	�޷���ֵ
	*/
	void ScrollToLetter(char letter);

private:
	/**
	* ���������б��ؼ�������Ϣ
	* @param[in] msg ��Ϣ�������Ϣ
	* @return bool true �������ݿؼ���Ϣ��false ֹͣ���ݿؼ���Ϣ
	*/
	bool OnScrollChange(ui::EventArgs* param);

	/**
	* �������ѿؼ�ͷ�񵥻���Ϣ
	* @param[in] msg ��Ϣ�������Ϣ
	* @return bool true �������ݿؼ���Ϣ��false ֹͣ���ݿؼ���Ϣ
	*/
	bool OnHeadImageClick(const std::string& uid, ui::EventArgs*);

private:
	/**
	* ��Ӧ�û��б��ı�Ļص�����
	* @param[in] change_type ���ѱ仯����
	* @param[in] accid �û�id
	* @return void �޷���ֵ
	*/
	void OnFriendListChange(FriendChangeType change_type, const std::string& accid);

	/**
	* ��Ӧ�û���Ϣ�ı�Ļص�����
	* @param[in] uinfos �û���Ϣ�б�
	* @return void �޷���ֵ
	*/
	void OnUserInfoChange(const std::list<nim::UserNameCard> &uinfos);

	/**
	* ��Ӧ�������ı�Ļص�����
	* @param[in] id �û�id
	* @param[in] is_black �Ƿ���������
	* @return void �޷���ֵ
	*/
	void OnBlackListChange(const std::string& id, bool is_black);

	/**
	* ��Ӧ�û�ͷ��ı�Ļص�����
	* @param[in] type ͷ������
	* @param[in] accid �û�id
	* @param[in] photo_path ͷ��·��
	* @return void �޷���ֵ
	*/
	void OnUserPhotoReady(PhotoType type, const std::string& accid, const std::wstring &photo_path);

private:
	ui::Label* tip_letter_;
	ui::TreeNode* pos_tip_;
	ui::TreeView* friend_list_;
	vector<ui::TreeNode*> tree_node_ver_;
	AutoUnregister unregister_cb;
};
}