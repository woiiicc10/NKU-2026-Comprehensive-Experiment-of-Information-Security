#include "Kmeans.h"

/*****************************************************************************************
********************************* 读取测试文件函数 ***************************************
*****************************************************************************************/
bool ReadTestFile(list <strMyRecord*>* pRecordList)
{
	FILE *pInFile;                                     //记录文件的指针
	int iTestCount;                                    //检测文件中的数据数目
	char szBuf[MAX_BUF_SIZE];                          //读文件缓存  MAX_BUF_SIZE = 512
	strMyRecord* pRecord;                              //遍历记录的指针

	string strTemp;
	char szSeps[] = ",\r\n";
	
	cout<<"Start reading records from test file!"<<endl;
	outfile<<"Start reading records from test file!"<<endl;	
	
	if ((pInFile = fopen("corrected_datatreat", "r")) == NULL)
	{
		cout<<"Open Test file faied !"<<endl;
		return false;
	}
	else
	{
		iTestCount = 0;
		while (fgets(szBuf, MAX_BUF_SIZE, pInFile) != NULL)
		{
			if(++iTestCount%10000 == 0)
				cout<<setiosflags(ios::left)<<setw(8)<<iTestCount<<"  lines have read ..."<<endl;

			pRecord = new  strMyRecord;
			//02 协议类型
			strTemp = strtok(szBuf, szSeps);
			pRecord->fProtocolType = (float)atof(strTemp.c_str());
			//03 服务类型
			strTemp = strtok(NULL, szSeps);
			pRecord->fService = (float)atof(strTemp.c_str());
			//04 状态标志
			strTemp = strtok(NULL, szSeps);
			pRecord->fStatusFlag = (float)atof(strTemp.c_str());
			//05 源到目的字节数
			strTemp = strtok(NULL, szSeps);
			pRecord->fSrcBytes = (float)atof(strTemp.c_str());
			//06 目的到源字节数
			strTemp = strtok(NULL, szSeps);
			pRecord->fDestBytes = (float)atof(strTemp.c_str());
			//11 登录失败次数
			strTemp = strtok(NULL, szSeps);
			pRecord->fFailedLogins = (float)atof(strTemp.c_str());
			//14 是否获得root用户权限不要
			strtok(NULL, szSeps);
			//16 root用户权限存取次数
			strTemp = strtok(NULL, szSeps);
			pRecord->fNumofRoot = (float)atof(strTemp.c_str());
			//22 是否是guest用户登录不要
			strtok(NULL, szSeps);
			//23 2秒内连接相同主机数目
			strTemp = strtok(NULL, szSeps);
			pRecord->fCount = (float)atof(strTemp.c_str());
			//24 2秒内连接相同端口数目
			strTemp = strtok(NULL, szSeps);
			pRecord->fSrvCount = (float)atof(strTemp.c_str());
			//27 "REJ"错误的连接数比率
			strTemp = strtok(NULL, szSeps);
			pRecord->fRerrorRate = (float)atof(strTemp.c_str());
			//29 连接到相同端口数比率
			strTemp = strtok(NULL, szSeps);
			pRecord->fSameSrvRate = (float)atof(strTemp.c_str());
			//30 连接到不同端口数比率
			strTemp = strtok(NULL, szSeps);
			pRecord->fDiffSrvRate = (float)atof(strTemp.c_str());
			//33 相同目的地相同端口连接数
			strTemp = strtok(NULL, szSeps);
			pRecord->fDstHostSrvCount = (float)atof(strTemp.c_str());
			//34 相同目的地相同端口连接数比率
			strTemp = strtok(NULL, szSeps);
			pRecord->fDstHostSameSrvRate = (float)atof(strTemp.c_str());
			//35 相同目的地不同端口连接数比率
			strTemp = strtok(NULL, szSeps);
			pRecord->fDstHostDiffSrvRate = (float)atof(strTemp.c_str());
			//36 相同目的地相同源端口连接比率
			strTemp = strtok(NULL, szSeps);
			pRecord->fDstHostSameSrcPortRate = (float)atof(strTemp.c_str());
			//37 不同主机连接相同端口比率
			strTemp = strtok(NULL, szSeps);
			pRecord->fDstHostSrvDiffHostRate = (float)atof(strTemp.c_str());
			//39 连接当前主机有S0错误的比率
			strTemp = strtok(NULL, szSeps);
			pRecord->fDstHostSrvSerrorRate = (float)atof(strTemp.c_str());
			//42 类型标签
			strTemp = strtok(NULL, szSeps);
			pRecord->iLabel = atoi(strTemp.c_str());
			
			//在链表尾部插入记录
		  pRecordList->push_back(pRecord);
		}
		
		cout<<iTestCount<<" Records have read from test file!"<<endl;			
		outfile<<iTestCount<<" Records have read from test file!"<<endl;		
		return true;
	}
}

/*****************************************************************************************
**************************** 将Label从int类型转换为string类型 ****************************
*****************************************************************************************/
string LabelInttoStr(int i)
{
	 string strLabel;
   switch(i)
   {
    	case 0:
    		strLabel = "normal";
    		break;
    	case 1:
    		strLabel = "dos";
    		break;
    	case 2:
    		strLabel = "probe";
    		break;
    	case 3:
    		strLabel = "ur2";
    		break;
    	case 4:
    		strLabel = "r2l";
    		break;
    	default:
    		strLabel = "!!ERROR!!";
    		break;    		
    }
    return strLabel;	
}

/*****************************************************************************************
**************************************** Main函数 **************************************** 
*****************************************************************************************/
int main()
{		
	int Kvalue;                                        //K值
	int iRightRcdNum;                                  //记录分类正确的记录数
	int TestRcdNum;                                    //参加检测的记录总数
	string strTrueLabel,strPreLabel;                   //真实标签与预测标签
	
	strMyRecord* pRecord;                              //遍历记录的指针
	list <strMyRecord*>* pTestRcdList;                 //测试数据链表
	list<strMyRecord*>::iterator TestListIter;         //记录链表的迭代器

	ClusterNode* pClusterNode;	                     //聚类节点指针
	ClusterTree* pClusterTree;                         //聚类树
	
	/*************************************************************************************
	*********** PART1 利用K-Means算法，对训练数据集进行迭代聚类，并创建聚类树 ************
	*************************************************************************************/
	
	pClusterTree = new ClusterTree();
	// 创建 KMeans 对象，初始 level 设为 1，维度数为 19（包含 label 字段）
	CKMeans* pKMeans = new CKMeans(pClusterTree, ++KmeansID, 1, 19);

	// 读取训练数据
	if(!pKMeans->ReadTrainingRecords())
	{
		cout<<"Read training records failed!"<<endl;
		return -1;
	}

	// 用户输入 K 值（若输入无效或为非正数，则使用默认 K=5）
	cout<<"Please input K value (enter 0 for default 5): ";
	if(!(cin>>Kvalue))
	{
		// 输入失败，清理输入流并使用默认
		cin.clear();
		cin.ignore(10000,'\n');
		Kvalue = 5;
	}
	if(Kvalue <= 0)
		Kvalue = 5;

	outfile<<"Set K = "<<Kvalue<<endl;

	// 运行 KMeans 算法
	pKMeans->RunKMeans(Kvalue);

	// 打印聚类树到屏幕与日志
	pClusterTree->Print();
	pClusterTree->PrintLog();


	/****************************************************************************************
	******* PART2 利用聚类树 对测试数据集中的数据进行类型预测，并计算出准确率和混淆矩阵******
	****************************************************************************************/  

	pTestRcdList = new list<strMyRecord*>();
	if(!ReadTestFile(pTestRcdList))
	{
		cout<<"Read test records failed!"<<endl;
		return -1;
	}

	ConfuseMatrix cm; // 创建混淆矩阵
	iRightRcdNum = 0; // 预测正确的记录数
	TestRcdNum = 0;   // 参加检测的记录总数

	// 遍历测试数据链表，为每个样本找到最近的聚类中心并统计
	for(TestListIter = pTestRcdList->begin(); TestListIter != pTestRcdList->end(); ++TestListIter)
	{
		pRecord = (*TestListIter);
		// 在聚类树中找到最近的聚类节点
		pClusterNode = pClusterTree->FindNearestCluster(pRecord);
		int iPreLabel = pClusterNode->GetClusterNodeLabel();
		int iTrueLabel = pRecord->iLabel;

		if(iPreLabel == iTrueLabel)
			iRightRcdNum++;

		// 更新混淆矩阵（真实标签, 预测标签）
		cm.UpdateValue(iTrueLabel, iPreLabel);

		// 将分类记录写到 Result.txt
		Rstfile<<LabelInttoStr(iTrueLabel)<<"\t"<<LabelInttoStr(iPreLabel)<<endl;

		TestRcdNum++;
	}

	// 打印结果与计算准确率
	cout<<"Total test records: "<<TestRcdNum<<endl;
	cout<<"Correctly classified: "<<iRightRcdNum<<endl;
	double accuracy = 0.0;
	if(TestRcdNum > 0)
		accuracy = (double)iRightRcdNum / (double)TestRcdNum * 100.0;
	cout<<"Accuracy = "<<accuracy<<" %"<<endl;
	outfile<<"Accuracy = "<<accuracy<<" %"<<endl;

	// 打印并记录混淆矩阵
	cm.PrintMatrix();
	cm.PrintMatrixToLog();

	return 0;
}
