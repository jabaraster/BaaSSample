//
//  NCMBQuery.h
//  NIFTY Cloud mobile backend
//
//  Created by NIFTY Corporation on 2013/04/17.
//  Copyright 2013 NIFTY Corporation All Rights Reserved.
//

#import <Foundation/Foundation.h>
#import "NCMBConstants.h"

/**
 NCMBQueryクラスはオブジェクトを検索するためのクエリを定義するクラスです。
 */
@interface NCMBQuery : NSObject

/** @name Create */

/**
 クラス名を指定してNCMBQueryのインスタンスを生成
 @param className 指定するクラス名
 */
+ (NCMBQuery *)queryWithClassName:(NSString *)className;


/**
 クラス名を指定してインスタンスを初期化
 @param className 指定するクラス名
 */
- (id)initWithClassName:(NSString *)className;


/// 指定するクラス名
@property (nonatomic,readonly) NSString *ncmbClassName;

/** @name Where */

/**
 子の情報も含めて親情報を取得。クエリに設定された検索条件で取得できるオブジェクトに加えて、各オブジェクトに格納された、キー（引数）のオブジェクトの情報も取得する。
 @param key 取得するキー
 */
- (void)includeKey:(NSString *)key;

/**
 「指定したキーの値が存在するオブジェクトを検索する」という検索条件を設定
 @param key 検索条件に使用するキー
 */
- (void)whereKeyExists:(NSString *)key;

/**
 「指定したキーの値が存在しないオブジェクトを検索する」という検索条件を設定
 @param key 検索条件に使用するキー
 */
- (void)whereKeyDoesNotExist:(NSString *)key;

/**
 「親クエリに指定したキーの値の中から指定したオブジェクト(第二引数)と等しいものを検索する」という検索条件を設定
 @param key 検索条件に使用するキー
 @param object 検索条件に使用する値(オブジェクト)
 */
- (void)whereKey:(NSString *)key equalTo:(id)object;

/**
 「親クエリに指定したキーの値の中から指定したオブジェクト(第二引数)の値より小さいものを検索」という検索条件を設定
 @param key 検索条件に使用するキー
 @param object 検索条件に使用する値(オブジェクト)
 */
- (void)whereKey:(NSString *)key lessThan:(id)object;

/**
 「親クエリに指定したキーの値の中から指定したオブジェクト(第二引数)の値以下のものを検索」という検索条件を設定
 @param key 検索条件に使用するキー
 @param object 検索条件に使用する値(オブジェクト)
 */
- (void)whereKey:(NSString *)key lessThanOrEqualTo:(id)object;

/**
 「親クエリに指定したキーの値の中から指定したオブジェクト(第二引数)の値より大きいものを検索」という検索条件を設定
 @param key 検索条件に使用するキー
 @param object 検索条件に使用する値(オブジェクト)
 */
- (void)whereKey:(NSString *)key greaterThan:(id)object;

/**
 「親クエリに指定したキーの値の中から指定したオブジェクト(第二引数)の値以上のものを検索」という検索条件を設定
 @param key 検索条件に使用するキー
 @param object 検索条件に使用する値(オブジェクト)
 */
- (void)whereKey:(NSString *)key greaterThanOrEqualTo:(id)object;

/**
 「親クエリに指定したキーの値の中から指定したオブジェクト(第二引数)と等しくないものを検索する」という検索条件を設定
 @param key 検索条件に使用するキー
 @param object 検索条件に使用する値(オブジェクト)
 */
- (void)whereKey:(NSString *)key notEqualTo:(id)object;

/**
 「指定したキーの値が指定した配列の値のうちいずれか１つと一致するものを検索」という検索条件を設定
 @param key 検索条件に使用するキー
 @param array 検索条件に使用する配列
 */
- (void)whereKey:(NSString *)key containedIn:(NSArray *)array;

/**
 「指定したキーに設定された配列の値と、指定した配列の値が１つ以上一致するものを検索」という検索条件を設定
 @param key 検索条件に使用するキー（指定したキーの値が配列）
 @param array 検索条件に使用する配列
 */
- (void)whereKey:(NSString *)key containedInArray:(NSArray *)array;

/**
 「指定したキーの値が指定した配列の値のいずれとも一致しないものを検索」という検索条件を設定
 @param key 検索条件に使用するキー
 @param array 検索条件に使用する配列
 */
- (void)whereKey:(NSString *)key notContainedIn:(NSArray *)array;

/**
 「指定したキーに設定された配列の値と、指定した配列の値が１つも一致しないものを検索」という検索条件を設定
 @param key 検索条件に使用するキー（指定したキーの値が配列）
 @param array 検索条件に使用する配列
 */
- (void)whereKey:(NSString *)key notContainedInArray:(NSArray *)array;

/**
 「指定したキーの値に対して、指定した配列の値が全て含まれるものを検索」という検索条件を設定。
 指定した配列の値が全て含まれている場合は、指定したキーの値の中に一致しないものが含まれている場合でも検索される
 @param key 検索条件に使用するキー（指定したキーの値が配列）
 @param array 検索条件に使用する配列
 */
- (void)whereKey:(NSString *)key containsAllObjectsInArray:(NSArray *)array;



/** @name Sub Queries */

/**
 「第一引数は親クエリにおけるキー、第二引数はサブクエリ（第三引数）におけるキーとし、親とサブクエリで得られた値の中で一致するものを検索」という検索条件を設定。
 @param key 親クエリにおけるキー
 @param otherKey サブクエリ（第三引数）におけるキー
 @param query サブクエリ
 */
- (void)whereKey:(NSString *)key matchesKey:(NSString *)otherKey inQuery:(NCMBQuery *)query;

/**
 「第一引数は親クエリにおけるキー、第二引数はサブクエリ（第三引数）におけるキーとし、親とサブクエリで得られた値の中で一致しないものを検索」という検索条件を設定。
 @param key 親クエリにおけるキー
 @param otherKey サブクエリ（第三引数）におけるキー
 @param query サブクエリ
 */
- (void)whereKey:(NSString *)key doesNotMatchKey:(NSString *)otherKey inQuery:(NCMBQuery *)query;

/**
 「サブクエリ（第二引数）で取得できるオブジェクトの内、親クエリに指定したキー（第一引数）の値(オブジェクト)と一致するものを検索」という検索条件を設定
 @param key 検索条件に使用するキー
 @param query 検索条件に使用するクエリ
 */
- (void)whereKey:(NSString *)key matchesQuery:(NCMBQuery *)query;

/**
 「サブクエリ（第二引数）で取得できるオブジェクトの内、親クエリに指定したキー（第一引数）のオブジェクトと一致しないものを検索」という検索条件を設定
 @param key 検索条件に使用するキー
 @param query 検索条件に使用するクエリ
 */
- (void)whereKey:(NSString *)key doesNotMatchQuery:(NCMBQuery *)query;

/**
 引数に与えたNCMBQueryのいずれかの条件に当てはまるオブジェクトを取得するための新規NCMBQueryを生成
 @param queries 条件にしたい複数のクエリ
 */
+ (NCMBQuery *)orQueryWithSubqueries:(NSArray *)queries;


/** @name Pagination */

/// limit データの取得件数。デフォルトは100件。
@property (nonatomic) NSInteger limit;

/// skip データ取得時の開始位置。デフォルトは０。
@property (nonatomic) NSInteger skip;


/** @name Order */

/**
 「指定したキーで昇順に並べ替える」という検索条件を設定。すでに並べ替え設定が存在している場合は上書きされる。
 @param key 並べ替えに使用するキー
 */
- (void)orderByAscending:(NSString *)key;

/**
 「指定したキーで昇順に並べ替える」という設定を検索条件に追加。すでに並べ替え設定が存在している場合は、既存のものより優先度が低い。
 @param key 並べ替えに使用するキー
 */
- (void)addAscendingOrder:(NSString *)key;

/**
 「指定したキーで降順に並べ替える」という検索条件を設定。すでに並べ替え設定が存在している場合は上書きされる。
 @param key 並べ替えに使用するキー
 */
- (void)orderByDescending:(NSString *)key;

/**
 「指定したキーで降順に並べ替える」という設定を検索条件に追加。すでに並べ替え設定が存在している場合は、既存のものより優先度が低い。
 @param key 並べ替えに使用するキー
 */
- (void)addDescendingOrder:(NSString *)key;

/**
 「指定したNSSortDescriptor通りに並べ替える」という検索条件を設定。すでに並べ替え設定が存在している場合は上書きされる。
 @param sortDescriptor 並び替えに使用するNSSortDescriptorのインスタンス
 */
- (void)orderBySortDescriptor:(NSSortDescriptor *)sortDescriptor;

/**
 「指定した複数のNSSortDescriptor通りに並べ替える」という検索条件を設定。すでに並べ替え設定が存在している場合は上書きされる。
 @param sortDescriptors 並び替えに使用するNSSortDescriptorのインスタンスが格納された配列
 */
- (void)orderBySortDescriptors:(NSArray *)sortDescriptors;


/** @name Getting Objects by ID */

/**
 指定したクラスとobjectIDを持つオブジェクトを取得
 @param objectClass 取得するオブジェクトのクラス名
 @param objectId 取得するオブジェクトのobjectID
 */
+ (NCMBObject *)getObjectOfClass:(NSString *)objectClass
                        objectId:(NSString *)objectId;

/**
 指定したクラスとobjectIDを持つオブジェクトを取得。必要があればエラーをセットし、取得することもできる。
 @param objectClass 取得するオブジェクトのクラス名
 @param objectId 取得するオブジェクトのobjectID
 @param error 処理中に起きたエラーのポインタ
 */
+ (NCMBObject *)getObjectOfClass:(NSString *)objectClass
                        objectId:(NSString *)objectId
                           error:(NSError **)error;

/**
 指定したobjectIDを持つオブジェクトを取得
 @param objectId 取得するオブジェクトのobjectID
  */
- (NCMBObject *)getObjectWithId:(NSString *)objectId;


/**
 指定したobjectIDを持つオブジェクトを取得。必要があればエラーをセットし、取得することもできる。
 @param objectId 取得するオブジェクトのobjectID
 @param error 処理中に起きたエラーのポインタ
  */
- (NCMBObject *)getObjectWithId:(NSString *)objectId error:(NSError **)error;


/**
 指定したobjectIDを持つオブジェクトを非同期で取得。取得し終わったら与えられたblockを呼び出す。
 @param objectId 取得するオブジェクトのobjectID
 @param block 通信後に実行されるblock。blockは次の引数のシグネチャを持つ必要がある (NCMBObject *object, NSError *error)
 objectには取得したオブジェクトが渡される。errorにはエラーがなければnilが渡される。
 */
- (void)getObjectInBackgroundWithId:(NSString *)objectId
                              block:(NCMBObjectResultBlock)block;

/**
 指定したobjectIDを持つオブジェクトを非同期で取得。取得し終わったら指定されたコールバックを呼び出す。
 @param objectId 取得するオブジェクトのobjectID
 @param target 呼び出すセレクタのターゲット
 @param selector 呼び出すセレクタ。次のシグネチャを持つ必要がある。 (void)callbackWithResult(NCMBObject)result error:(NSError )error
 resultには取得したオブジェクトが渡され、当てはまるものがなければnilが渡される。errorにはエラーがなければnilが渡される。
 */
- (void)getObjectInBackgroundWithId:(NSString *)objectId
                             target:(id)target
                           selector:(SEL)selector;


/** @name Getting User */

/**
 指定したobjectIDのユーザを取得
 @param objectId 取得するユーザのobjectID
 */
+ (NCMBUser *)getUserObjectWithId:(NSString *)objectId;

/**
 指定したobjectIDのユーザを取得。必要があればエラーをセットし、取得することもできる。
 @param objectId 取得するユーザのobjectID
 @param error 処理中に起きたエラーのポインタ
 */
+ (NCMBUser *)getUserObjectWithId:(NSString *)objectId
                            error:(NSError **)error;


/** @name Find Objects */

/**
 設定されている検索条件に当てはまるオブジェクトを取得
 */
- (NSArray *)findObjects;


/**
 設定されている検索条件に当てはまるオブジェクトを取得。必要があればエラーをセットし、取得することもできる。
 @param error 処理中に起きたエラーのポインタ
  */
- (NSArray *)findObjects:(NSError **)error;

/**
 設定されている検索条件に当てはまるオブジェクトを非同期で取得。取得し終わったら与えられたblockを呼び出す。
 @param block 信後に実行されるblock。blockは次の引数のシグネチャを持つ必要がある（NSArray *objects, NSError *error）
 objectsには取得したオブジェクトが渡される。errorにはエラーがなければnilが渡される。
 */
- (void)findObjectsInBackgroundWithBlock:(NCMBArrayResultBlock)block;

/**
 設定されている検索条件に当てはまるオブジェクトを非同期で取得。取得し終わったら指定されたコールバックを呼び出す。
 @param target 呼び出すセレクタのターゲット
 @param selector 呼び出すセレクタ。次のシグネチャを持つ必要がある。(void)callbackWithResult:(NSArray )result error:(NSError )error.
 resultには取得したオブジェクトが渡され、当てはまるものがなければnilが渡される。errorにはエラーがなければnilが渡される。
 */
- (void)findObjectsInBackgroundWithTarget:(id)target selector:(SEL)selector;

/** @name Get First Object */

/**
 設定されている検索条件に当てはまるオブジェクトを一件取得
 */
- (NCMBObject *)getFirstObject;

/**
 設定されている検索条件に当てはまるオブジェクトを一件取得。必要があればエラーをセットし、取得することもできる。
 @param error 処理中に起きたエラーのポインタ
  */
- (NCMBObject *)getFirstObject:(NSError **)error;


/**
 設定されている検索条件に当てはまるオブジェクト一件を非同期で取得。取得し終わったら与えられたblockを呼び出す。
 @param block 通信後に実行されるblock。blockは次の引数のシグネチャを持つ必要がある（NCMBObject *object, NSError *error）
 objectには取得したオブジェクトが渡される。errorにはエラーがなければnilが渡される。
 */
- (void)getFirstObjectInBackgroundWithBlock:(NCMBObjectResultBlock)block;

/**
 設定されている検索条件に当てはまるオブジェクト一件を非同期で取得。取得し終わったら指定されたコールバックを呼び出す。
 @param target 呼び出すセレクタのターゲット
 @param selector 呼び出すセレクタ。次のシグネチャを持つ必要がある。 (void)callbackWithResult:(NCMBObject)result error:(NSError )error
 resultには取得したオブジェクトが渡され、当てはまるものがなければnilが渡される。errorにはエラーがなければnilが渡される。
 */
- (void)getFirstObjectInBackgroundWithTarget:(id)target selector:(SEL)selector;

/** @name Count Objects */

/**
 設定されている検索条件に当てはまるオブジェクトの件数を取得
  */
- (NSInteger)countObjects;

/**
 設定されている検索条件に当てはまるオブジェクトの件数を取得。必要があればエラーをセットし、取得することもできる。
 @param error 処理中に起きたエラーのポインタ
 */
- (NSInteger)countObjects:(NSError **)error;

/**
 設定されている検索条件に当てはまるオブジェクトの件数を非同期で取得。取得し終わったら与えられたblockを呼び出す。
 @param block 通信後に実行されるblock。blockは次の引数のシグネチャを持つ必要がある (int number, NSError *error)
 countには取得した件数が渡される。errorにはエラーがなければnilが渡される。
 */
- (void)countObjectsInBackgroundWithBlock:(NCMBIntegerResultBlock)block;

/**
 設定されている検索条件に当てはまるオブジェクトの件数を非同期で取得。取得し終わったら指定されたコールバックを呼び出す。
 @param target 呼び出すセレクタのターゲット
 @param selector 呼び出すセレクタ。次のシグネチャを持つ必要がある。(void)callbackWithResult:(NSNumber )result error:(NSError )error
 resultには取得した件数が渡される。errorにはエラーがなければnilが渡される。 */
- (void)countObjectsInBackgroundWithTarget:(id)target selector:(SEL)selector;

/** @name Cancel */

/**
 非同期通信をキャンセルする。通信キャンセル後、コールバックは呼ばれない。
 */
- (void)cancel;


/** @name Cache */

/// データ取得の際の、キャッシュの仕様を指定（キャッシュを使用する、しないなど）。デフォルトの設定はkNCMBCachePolicyIgnoreCacheでキャッシュは使用せず、新規のキャッシュも行わない。
@property (readwrite, assign) NCMBCachePolicy cachePolicy;

/// キャッシュを残す時間。デフォルトは無制限。
@property (readwrite, assign) NSTimeInterval maxCacheAge;

/**
 設定されている検索条件に当てはまるキャッシュの有無を取得
 */
- (BOOL)hasCachedResult;

/**
 設定されている検索条件に当てはまるキャッシュをクリア
 */
- (void)clearCachedResult;

/**
 全てのキャッシュをクリア
 */
+ (void)clearAllCachedResults;

@end
