# LightHead

An educational project for implementing various data structures and looking for their usecases.

## Roadmap

- [ ] B-tree
- [ ] Prefix tree
- [x] Van Emde-Boas tree
- [ ] MinHash
- [ ] Trie
- [ ] Fenwick Tree
- [ ] Order Statistic Tree

<!--

#### Tarantool

- [ ] [Transaction manageer optimizations](https://github.com/tarantool/tarantool/issues/5172)
- [ ] [Optimize and improve streams](https://github.com/tarantool/tarantool/issues/6316)
- [ ] [Speed-up non-indexed tuple field access](https://github.com/tarantool/tarantool/issues/1309)
- [ ] [Cbench](https://github.com/tarantool/cbench/tree/master/cbench)
- [ ] [small](https://habr.com/ru/companies/vk/articles/525484/)

#### Benchmarking

- [ ] [LLVM Benchmarking Tutorial](https://llvm.org/docs/Benchmarking.html)

#### System

- [ ] Linux AIO
- [ ] Linux [uring](https://habr.com/ru/articles/589389/)
- [ ] [DPDK](https://www.youtube.com/watch?v=FSQJFAcIWdU&list=PLhhTXwj6_Fl0ZC8DyV8E4NkWCVd-Hifa8)
- [ ] Linkers and loaders (book)
- [ ] [Linkers](https://www.airs.com/blog/archives/38)
- [ ] [Linux SMP alternatives](https://lwn.net/Articles/164121/)
- [ ] [SMP of WingOS](https://github.com/mtgplayer2/WingOS_x64/)
- [ ] O_DIRECT
- [ ] gRPC (Remote Procedure Call)

#### Optimization

- [ ] Memory barriers
- [ ] Line fill buffer
- [ ] [Always measure one level deeper](https://cacm.acm.org/magazines/2018/7/229031-always-measure-one-level-deeper/fulltext)
- [ ] [Optimizing SW occlusion culling](https://fgiesen.wordpress.com/2013/02/17/optimizing-sw-occlusion-culling-index/)
- [ ] [NAT Performance Tuning Tutorial](https://github.com/NAThompson/performance_tuning_tutorial)
- [ ] Cumulative distribution (https://en.wikipedia.org/wiki/Cumulative_distribution_function)
- [ ] [Postrge SQL Dynamic Trace](https://www.postgresql.org/docs/current/dynamic-trace.html) ([Tarantool GSOC](https://github.com/tarantool/tarantool/wiki/Tarantool-Summer-of-Code-2022-ideas#introduce-dynamic-trace-probes-to-tarantool-kernel-for-systemtapdtrace))
- [ ] [Perf](https://www.brendangregg.com/perf.html)
- [ ] Mutithreaded [profiling](https://www.youtube.com/watch?v=d_3kCXSONWQ)
- [ ] Fast [parsing](https://www.youtube.com/watch?v=GcAJF4648JI)
- [ ] [Assembler](https://www.youtube.com/watch?v=woeVYeC7ktc&t=2138s)
- [ ] [SIMD](https://www.officedaytime.com/simd512e/)
- [ ] SIMD parsing.
- [ ] CPU [internal structure](https://www.youtube.com/watch?v=7aA6CTwnz7c&t=1390s)
- [ ] [Benchmarking](https://superuser.com/questions/320529/how-to-create-a-linux-system-that-runs-a-single-application)
- [ ] NOHS [mode](https://www.kernel.org/doc/Documentation/timers/NO_HZ.txt)
- [ ] My journey to stable benchmark, parts [1](https://vstinner.github.io/journey-to-stable-benchmark-system.html), [2](https://vstinner.github.io/journey-to-stable-benchmark-deadcode.html), [3](https://vstinner.github.io/journey-to-stable-benchmark-average.html)
- [ ] [Statistics for experiments](https://pages.stat.wisc.edu/~yxu/Teaching/16%20spring%20Stat602/%5BGeorge_E._P._Box,_J._Stuart_Hunter,_William_G._Hu(BookZZ.org).pdf) (page 100)
- [ ] Randomization distribution
- [ ] Geometric mean
- [ ] Page 100
- [ ] [AFMH](https://en.algorithmica.org/hpc/)
- [ ] SO X86 [Wiki](https://stackoverflow.com/tags/x86/info)
- [ ] [Is software prefetching useful for performance?](https://lemire.me/blog/2018/04/30/is-software-prefetching-__builtin_prefetch-useful-for-performance/)
- [ ] [Answer to "Is software prefetching useful for performance"](http://alexanius-blog.blogspot.com/2018/05/answer-to-is-software-prefetching.html)
- [ ] [How I got 2x speedup with one line of code](https://news.ycombinator.com/item?id=6734292)
- [ ] Spurious regression.
- [ ] Spurious correlation probability.
- [ ] Null-hipotesis.
- [ ] P-value.
- [ ] [Why does gcc builtin prefetch not improve performance?](https://stackoverflow.com/questions/29203294/why-does-gcc-builtin-prefetch-not-improve-performance)
- [ ] [Cost of branch](https://en.algorithmica.org/hpc/pipelining/branching/)
- [ ] [Instruction measurement](https://arxiv.org/pdf/1810.04610.pdf)

#### Verification

- [ ] Memory [safety](https://stanford-cs242.github.io/f18/lectures/05-1-rust-memory-safety.html)
- [ ] LDRA
- [ ] Semgrep
- [ ] Coccinelle

#### Concurrency

- [ ] [Promela - multuthreading implementation](https://spinroot.com/spin/Man/Intro.html)
- [ ] [Multithreaded Performance Analisys](https://easyperf.net/blog/2019/10/05/Performance-Analysis-Of-MT-apps)
- [ ] Cooperative tree (each part of the tree has a core attached who can write this part, so we allow simulaneous writes, reads are unlimited).
- [ ] Peterson's Algorithm
- [ ] Intel Palm Tree
- [ ] Linux lockless page cache
- [ ] [Spinlock implementation](https://stackoverflow.com/questions/26583433/c11-implementation-of-spinlock-using-header-atomic)
- [ ] [Mistakes](https://habr.com/ru/articles/174369/)
- [ ] [Lock-fee List](https://habr.com/ru/articles/317882/)
- [ ] [About sinlocks](https://habr.com/ru/articles/689310/)
- [ ] [Memory Models](https://www.youtube.com/watch?v=SIZmLPtcZiE)
- [ ] [Port Contention](https://easyperf.net/blog/2018/03/21/port-contention)
- [ ] [Port 7](https://blogs.fau.de/hager/archives/8683)
- [ ] [SSE mov instructions](https://www.gamedev.net/blog/615/entry-2250281-demystifying-sse-move-instructions/)
- [ ] [SIMD blog](http://0x80.pl/)
- [ ] [SSE opcode list](https://softpixel.com/~cwright/programming/simd/sse.php)
- [ ] [SSE resources](https://stackoverflow.com/tags/sse/info)
- [ ] [SSE array sum](https://stackoverflow.com/questions/10930595/sse-instructions-to-add-all-elements-of-an-array)
- [ ] [SIMD 8 horisontal sums](https://stackoverflow.com/questions/51274287/computing-8-horizontal-sums-of-eight-avx-single-precision-floating-point-vectors)
- [ ] [SIMD atoi](https://stackoverflow.com/questions/35127060/how-to-implement-atoi-using-simd/35132718)
- [ ] [Conflict-free replicated data types](https://en.wikipedia.org/wiki/Conflict-free_replicated_data_type)

#### Data structures and algorithms

- [ ] [Extendible Hashing](https://en.wikipedia.org/wiki/Extendible_hashing)
- [ ] [Dash Hash](https://arxiv.org/abs/2003.07302)
- [ ] [Very Lightweight Locking](https://www.cs.umd.edu/~abadi/papers/vldbj-vll.pdf)
- [ ] [Segment tree](https://en.wikipedia.org/wiki/Segment_tree)
- [ ] Z-curve
- [ ] ClickHouse Data Skipping Index
- [ ] Radix sort
- [ ] Binary search [optimization tricks](https://www.youtube.com/watch?v=1RIPMQQRBWk)
- [ ] [Aho-Corasick Algorithm](https://en.wikipedia.org/wiki/Aho%E2%80%93Corasick_algorithm)
- [ ] Roaring Bitmap
- [ ] Just Bitmap
- [ ] Merge Tree
- [ ] Прошитое двиочное дерево
- [ ] Scapegoat Tree
- [ ] RTree
- [ ] RR* Tree
- [ ] Kukushka Hash
- [ ] B-tree (B+-tree, B+*-tree)
- [ ] LSM tree
- [ ] Red-black tree
- [ ] Dense map
- [ ] BM25 ragning
- [ ] Sparse Set
- [ ] Bloom Filter
- [ ] XOR filter
- [ ] T-Digest
- [ ] Skiplist
- [ ] Trie
- [ ] CTrie
- [ ] Radix tree
- [ ] Burst Trie
- [ ] HAT-Trie
- [ ] [Masstree](https://www.the-paper-trail.org/post/masstree-paper-notes/)
- [ ] [Interval Tree](https://en.wikipedia.org/wiki/Interval_tree)
- [ ] [Splay Tree](https://en.wikipedia.org/wiki/Splay_tree)
- [ ] [Rope](https://en.wikipedia.org/wiki/Rope_(data_structure))
- [ ] [HyperLogLog](https://en.wikipedia.org/wiki/HyperLogLog)
- [ ] [Van Emde Boas tree](https://en.wikipedia.org/wiki/Van_Emde_Boas_tree)
- [ ] [Patricia Tree](https://xlinux.nist.gov/dads/HTML/patriciatree.html)
- [ ] [Succinct data structure](https://en.wikipedia.org/wiki/Succinct_data_structure)
- [ ] [Partially ordered set](https://en.wikipedia.org/wiki/Partially_ordered_set)
- [ ] [Y-fast trie](https://en.wikipedia.org/wiki/Y-fast_trie)
- [ ] [k-NN index](https://opensearch.org/docs/latest/search-plugins/knn/knn-index/)
- [ ] [tANS](https://www.researchgate.net/figure/Example-of-generation-of-tANS-tables-for-s3documentclass12ptminimal_fig2_346490080)
- [ ] [Quickselect](https://habr.com/ru/articles/346930/)
- [ ] [Block Range Index](https://en.wikipedia.org/wiki/Block_Range_Index)
- [ ] [Binary Heap](https://en.wikipedia.org/wiki/Binary_heap)
- [ ] [2–3 heap](https://en.wikipedia.org/wiki/2%E2%80%933_heap)
- [ ] fib-heap
- [ ] [Heightmap](https://en.wikipedia.org/wiki/Heightmap)
- [ ] [Rolling Hash](https://www.geeksforgeeks.org/introduction-to-rolling-hash-data-structures-and-algorithms/)
- [ ] [Difference List](https://en.wikipedia.org/wiki/Difference_list)
- [ ] [KD-Tree](https://en.wikipedia.org/wiki/K-d_tree)
- [ ] [Priority Queue](https://en.wikipedia.org/wiki/Priority_queue) (on the [binary heap](https://www.geeksforgeeks.org/priority-queue-using-binary-heap/))
- [ ] [Apache Avro](https://en.wikipedia.org/wiki/Apache_Avro)
- [ ] [Apache Parquet](https://en.wikipedia.org/wiki/Apache_Parquet)

#### Compression

- [ ] PForDelta
- [ ] [Frame Of Reference](https://dbms-arch.fandom.com/wiki/Frame_of_Reference_(Compression_Scheme))
- [ ] Elias
- [ ] Rice
- [ ] Golomb
- [ ] Huffman
- [ ] Arithmetic
- [ ] Range Cored
- [ ] ANS
- [ ] S9
- [ ] S16
- [ ] Varint
- [ ] Group Varint
- [ ] LSIC
- [ ] Roundoff
- [ ] Bitmaps (table lookup)
- [ ] Deltas
- [ ] LUTs
- [ ] Frequency & Dictionaries
- [ ] LZ77/78
- [ ] LZW
- [ ] LZMA
- [ ] PPM
- [ ] PAQ
- [ ] Context Modeling
- [ ] LZ4
- [ ] ZSTD
- [ ] Brotli
- [ ] Snappy

#### Databases

- [ ] Hazelcast
- [ ] Gridgain
- [ ] [SAP Hana](https://www.sap.com/central-asia-caucasus/products/data-cloud/hana/what-is-sap-hana.html)
- [ ] [SingleStore](https://en.m.wikipedia.org/wiki/SingleStore)
- [ ] Yugabyte
- [ ] CockroachDB
- [ ] Redis Enterprise
- [ ] Postgres Google Cloud SQL
- [ ] DynamoDB
- [ ] Gigaspaces
- [ ] [VoltDB](https://en.wikipedia.org/wiki/VoltDB)
- [ ] [Chronicle Map](https://github.com/OpenHFT/Chronicle-Map)
- [ ] [RethinkDB](https://github.com/rethinkdb/rethinkdb)
- [ ] [Datastax Enterprise](https://www.datastax.com/products/datastax-enterprise)
- [ ] [Apache Geode](https://geode.apache.org/)
- [ ] [2-phase locking](https://en.wikipedia.org/wiki/Two-phase_locking)
- [ ] [Paxos](https://en.wikipedia.org/wiki/Paxos_(computer_science)), [Byzantine Paxos](https://lamport.azurewebsites.net/tla/byzpaxos.html), Multipaxos, Paxos Made Live, Paxos Made Simple, Part-Time Parlament
- [ ] Raft - an understandable consensus algorithm
- [ ] Practical Byzantine Fault Tolerance
- [ ] Accord ([Fast General Purpose Transactions](https://www.google.com/url?sa=t&rct=j&q=&esrc=s&source=web&cd=&cad=rja&uact=8&ved=2ahUKEwj_5JvM6vyBAxXPCRAIHc2qC_oQFnoECBEQAQ&url=https%3A%2F%2Fcwiki.apache.org%2Fconfluence%2Fdownload%2Fattachments%2F188744725%2FAccord.pdf%3Fversion%3D1%26modificationDate%3D1630847737000%26api%3Dv2&usg=AOvVaw3cfNqH-7DHxhDMuDSg4DQJ&opi=89978449))
- [ ] [RocksDB](https://en.wikipedia.org/wiki/RocksDB)
- [ ] Cassandra
- [ ] YDB (MVCC, distributed transactions)
- [ ] Apache Ignite
- [ ] Apache ZooKeeper
- [ ] Yandex Message Queue
- [ ] Apache Calcite
- [ ] Hazelcast
- [ ] Querify Labs
- [ ] MySQL (Replication, [isolation levels](https://dev.mysql.com/doc/refman/8.0/en/innodb-transaction-isolation-levels.html))
- [ ] PostgreSQL ([MVCC](https://www.postgresql.org/docs/current/mvcc.html) or [this](https://devcenter.heroku.com/articles/postgresql-concurrency) or [that](https://www.postgresql.org/docs/7.1/mvcc.html) pr [whatever](https://en.wikibooks.org/wiki/PostgreSQL/MVCC), [VACUUM](https://www.enterprisedb.com/postgres-tutorials/why-we-need-vacuum-implement-mvcc-postgresql), concurrency, logical replication, [isolation levels](https://www.postgresql.org/docs/current/transaction-iso.html))
- [ ] Scylladb
- [ ] Calvin transaction protocol
- [ ] Write Skew
- [ ] Two Phase Commit
- [ ] Saga
- [ ] [Serializable snapshot isolation](https://docs.google.com/presentation/d/1XnhlPU11nXdedBe6sdqldOpYe1X2ZdQM2g_aqJfGr0Y/htmlpresent)
- [ ] [Implementing MVCC](https://xnerv.wang/implementing-your-own-transactions-with-mvcc/)
- [ ] [CQRS Event Sourcing](https://habr.com/ru/articles/146429/)
- [ ] CosmosDB Azure consistency options
- [ ] Google Cloud Spanner
- [ ] Standby in distributed systems
- [ ] Microsoft Orleans transactions
- [ ] GOSSIP ([eficient implementations](https://netsec.ethz.ch/publications/papers/gossip2015.pdf), [alternative protocol](https://ceur-ws.org/Vol-3041/508-513-paper-94.pdf))
- [ ] [Oracle MVCC](https://docs.oracle.com/cd/E17276_01/html/bdb-sql/mvcc.html)
- [ ] MVCC implementations: [mvcc11](https://github.com/kennethho/mvcc11), [tihku](https://github.com/penberg/tihku), [how it works](https://www.theserverside.com/blog/Coffee-Talk-Java-News-Stories-and-Opinions/What-is-MVCC-How-does-Multiversion-Concurrencty-Control-work)
- [ ] Amazon MemoryDB
- [ ] Queues, message brokers and [Analytics](https://developer.redis.com/howtos/analytics/) on Redis
- [ ] [ACID](https://en.wikipedia.org/wiki/ACID) or [this](https://www.geeksforgeeks.org/acid-properties-in-dbms/)
- [ ] [CAP](https://en.wikipedia.org/wiki/CAP_theorem) theorem
- [ ] [Snapshot Isolation](https://en.wikipedia.org/wiki/Snapshot_isolation)
- [ ] [Concurrency Control](https://www.geeksforgeeks.org/concurrency-control-in-dbms/)
- [ ] [Isolation Levels](https://www.geeksforgeeks.org/transaction-isolation-levels-dbms/) or [this](https://en.wikipedia.org/wiki/Isolation_(database_systems))
- [ ] Redis ([data types](https://redis.io/docs/data-types/), [transactions](https://redis.io/docs/interact/transactions/))
- [ ] [Consistency Models](https://jepsen.io/consistency)
- [ ] Kafka
- [ ] [Why does Neon use Paxos](https://neon.tech/blog/paxos)
- [ ] Dragonfly

#### Compilers

- [ ] [ANF](https://en.wikipedia.org/wiki/A-normal_form)
- [ ] Futamura Projections
- [ ] Сеть Петри
- [ ] [How LLVM optimizes a function](https://blog.regehr.org/archives/1603)
- [ ] [LLVM EarlyCSE](https://llvm.org/doxygen/EarlyCSE_8cpp_source.html)
- [ ] [Indutcion Variable Pimizations](https://www.cs.cornell.edu/courses/cs6120/2019fa/blog/ive/)
- [ ] [SPMD](https://ispc.github.io)
- [ ] [MLIR](https://mlir.llvm.org/)

#### Fun

- [ ] 3D Software Rendering
- [ ] WASM implementation

#### Gamedev

- [ ] [Euphoria](https://gta.fandom.com/wiki/Euphoria) (GTA human character physics engine)
- [ ] [Hierarchical task network](https://en.wikipedia.org/wiki/Hierarchical_task_network)
- [ ] [GOAP](https://leopotam.ru/33/) (Goal Oriented Action Planning)
- [ ] Иерархические конечные автоматы
- [ ] [Деревья поведений](https://leopotam.ru/43/)

#### Vector Engine

- [ ] Approximate Nearest Neighbor
- [ ] Dot Product
- [ ] Product Quantization
- [ ] IVFPQ (Inverted Vector File (inverted file index) with Product Quantization)
- [ ] Hierarchical Navigable Small World (Proximity Graph, Greedy Search, Yunable Precision)
- [ ] ANNOY (Approximate Nearest Neighbors Oh Yeah)
- [ ] Inverted Indexes
- [ ] Quantisation (quantized representation), Oversampling, after findgin 100 results rescoring using original representation.
- [ ] Repressenting one dimention by a single bit and doing xor + popcnt to compare these

There's filtering required sometimes. Like we want everythingsimilar to this vector, but also it should have price less than $30. So here we can do 1 pre-filtering and 2 post-filtering. 1 we perform search on list of candidates (building  candidate  list can be vary expensive), on 2 we perform filtering after gttting next bunch of results. QDrant uses in-place filtering. But sometimes the filtering is so strict that is detaouches the traversing graph from another tellure that has the required results. Here Percolation theory comes. They create links between nodes describing the filtering conditions (like price).


-->
