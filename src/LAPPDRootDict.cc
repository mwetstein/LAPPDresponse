//
// File generated by rootcint at Mon Nov 24 00:01:52 2014

// Do NOT change. Changes will be lost next time file is generated
//

#define R__DICTIONARY_FILENAME dOdIsrcdILAPPDRootDict
#include "RConfig.h" //rootcint 4834
#if !defined(R__ACCESS_IN_SYMBOL)
//Break the privacy of classes -- Disabled for the moment
#define private public
#define protected public
#endif

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;
#include "LAPPDRootDict.h"

#include "TClass.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"

// Direct notice to TROOT of the dictionary's loading.
namespace {
   static struct DictInit {
      DictInit() {
         ROOT::RegisterModule();
      }
   } __TheDictionaryInitializer;
}

// START OF SHADOWS

namespace ROOT {
   namespace Shadow {
   } // of namespace Shadow
} // of namespace ROOT
// END OF SHADOWS

namespace ROOT {
   void LAPPDresponse_ShowMembers(void *obj, TMemberInspector &R__insp);
   static void *new_LAPPDresponse(void *p = 0);
   static void *newArray_LAPPDresponse(Long_t size, void *p);
   static void delete_LAPPDresponse(void *p);
   static void deleteArray_LAPPDresponse(void *p);
   static void destruct_LAPPDresponse(void *p);
   static void streamer_LAPPDresponse(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::LAPPDresponse*)
   {
      ::LAPPDresponse *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::LAPPDresponse >(0);
      static ::ROOT::TGenericClassInfo 
         instance("LAPPDresponse", ::LAPPDresponse::Class_Version(), "./include/LAPPDresponse.hh", 7,
                  typeid(::LAPPDresponse), DefineBehavior(ptr, ptr),
                  &::LAPPDresponse::Dictionary, isa_proxy, 0,
                  sizeof(::LAPPDresponse) );
      instance.SetNew(&new_LAPPDresponse);
      instance.SetNewArray(&newArray_LAPPDresponse);
      instance.SetDelete(&delete_LAPPDresponse);
      instance.SetDeleteArray(&deleteArray_LAPPDresponse);
      instance.SetDestructor(&destruct_LAPPDresponse);
      instance.SetStreamerFunc(&streamer_LAPPDresponse);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::LAPPDresponse*)
   {
      return GenerateInitInstanceLocal((::LAPPDresponse*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::LAPPDresponse*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr LAPPDresponse::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *LAPPDresponse::Class_Name()
{
   return "LAPPDresponse";
}

//______________________________________________________________________________
const char *LAPPDresponse::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::LAPPDresponse*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int LAPPDresponse::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::LAPPDresponse*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
void LAPPDresponse::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::LAPPDresponse*)0x0)->GetClass();
}

//______________________________________________________________________________
TClass *LAPPDresponse::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gCINTMutex); if(!fgIsA) {fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::LAPPDresponse*)0x0)->GetClass();} }
   return fgIsA;
}

//______________________________________________________________________________
void LAPPDresponse::Streamer(TBuffer &R__b)
{
   // Stream an object of class LAPPDresponse.

   TObject::Streamer(R__b);
}

//______________________________________________________________________________
void LAPPDresponse::ShowMembers(TMemberInspector &R__insp)
{
      // Inspect the data members of an object of class LAPPDresponse.
      TClass *R__cl = ::LAPPDresponse::IsA();
      if (R__cl || R__insp.IsA()) { }
      R__insp.Inspect(R__cl, R__insp.GetParent(), "_freezetime", &_freezetime);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "*_templatepulse", &_templatepulse);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "*_PHD", &_PHD);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "*_pulsewidth", &_pulsewidth);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "_noiselevel", &_noiselevel);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "_nsamples", &_nsamples);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "_samplewidth", &_samplewidth);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "*StripResponse_neg", &StripResponse_neg);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "*StripResponse_pos", &StripResponse_pos);
      TObject::ShowMembers(R__insp);
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_LAPPDresponse(void *p) {
      return  p ? new(p) ::LAPPDresponse : new ::LAPPDresponse;
   }
   static void *newArray_LAPPDresponse(Long_t nElements, void *p) {
      return p ? new(p) ::LAPPDresponse[nElements] : new ::LAPPDresponse[nElements];
   }
   // Wrapper around operator delete
   static void delete_LAPPDresponse(void *p) {
      delete ((::LAPPDresponse*)p);
   }
   static void deleteArray_LAPPDresponse(void *p) {
      delete [] ((::LAPPDresponse*)p);
   }
   static void destruct_LAPPDresponse(void *p) {
      typedef ::LAPPDresponse current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_LAPPDresponse(TBuffer &buf, void *obj) {
      ((::LAPPDresponse*)obj)->::LAPPDresponse::Streamer(buf);
   }
} // end of namespace ROOT for class ::LAPPDresponse

/********************************************************
* ./src/LAPPDRootDict.cc
* CAUTION: DON'T CHANGE THIS FILE. THIS FILE IS AUTOMATICALLY GENERATED
*          FROM HEADER FILES LISTED IN G__setup_cpp_environmentXXX().
*          CHANGE THOSE HEADER FILES AND REGENERATE THIS FILE.
********************************************************/

#ifdef G__MEMTEST
#undef malloc
#undef free
#endif

#if defined(__GNUC__) && __GNUC__ >= 4 && ((__GNUC_MINOR__ == 2 && __GNUC_PATCHLEVEL__ >= 1) || (__GNUC_MINOR__ >= 3))
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif

extern "C" void G__cpp_reset_tagtableLAPPDRootDict();

extern "C" void G__set_cpp_environmentLAPPDRootDict() {
  G__add_compiledheader("TObject.h");
  G__add_compiledheader("TMemberInspector.h");
  G__add_compiledheader("LAPPDresponse.hh");
  G__cpp_reset_tagtableLAPPDRootDict();
}
#include <new>
extern "C" int G__cpp_dllrevLAPPDRootDict() { return(30051515); }

/*********************************************************
* Member function Interface Method
*********************************************************/

/* LAPPDresponse */
static int G__LAPPDRootDict_215_0_1(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
   LAPPDresponse* p = NULL;
   char* gvp = (char*) G__getgvp();
   int n = G__getaryconstruct();
   if (n) {
     if ((gvp == (char*)G__PVOID) || (gvp == 0)) {
       p = new LAPPDresponse[n];
     } else {
       p = new((void*) gvp) LAPPDresponse[n];
     }
   } else {
     if ((gvp == (char*)G__PVOID) || (gvp == 0)) {
       p = new LAPPDresponse;
     } else {
       p = new((void*) gvp) LAPPDresponse;
     }
   }
   result7->obj.i = (long) p;
   result7->ref = (long) p;
   G__set_tagnum(result7,G__get_linked_tagnum(&G__LAPPDRootDictLN_LAPPDresponse));
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__LAPPDRootDict_215_0_2(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((LAPPDresponse*) G__getstructoffset())->SetFreezeTime((double) G__double(libp->para[0]));
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__LAPPDRootDict_215_0_3(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((LAPPDresponse*) G__getstructoffset())->AddPhoton((double) G__double(libp->para[0]), (double) G__double(libp->para[1])
, (double) G__double(libp->para[2]));
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__LAPPDRootDict_215_0_4(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 85, (long) ((LAPPDresponse*) G__getstructoffset())->CalcSinglePhotonTrace((int) G__int(libp->para[0]), (double) G__double(libp->para[1])
, (double) G__double(libp->para[2]), (double) G__double(libp->para[3])
, (int) G__int(libp->para[4])));
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__LAPPDRootDict_215_0_5(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 85, (long) ((LAPPDresponse*) G__getstructoffset())->GetTrace((int) G__int(libp->para[0]), (int) G__int(libp->para[1])));
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__LAPPDRootDict_215_0_8(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 85, (long) LAPPDresponse::Class());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__LAPPDRootDict_215_0_9(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 67, (long) LAPPDresponse::Class_Name());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__LAPPDRootDict_215_0_10(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 115, (long) LAPPDresponse::Class_Version());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__LAPPDRootDict_215_0_11(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      LAPPDresponse::Dictionary();
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__LAPPDRootDict_215_0_15(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((LAPPDresponse*) G__getstructoffset())->StreamerNVirtual(*(TBuffer*) libp->para[0].ref);
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__LAPPDRootDict_215_0_16(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 67, (long) LAPPDresponse::DeclFileName());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__LAPPDRootDict_215_0_17(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 105, (long) LAPPDresponse::ImplFileLine());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__LAPPDRootDict_215_0_18(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 67, (long) LAPPDresponse::ImplFileName());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__LAPPDRootDict_215_0_19(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 105, (long) LAPPDresponse::DeclFileLine());
   return(1 || funcname || hash || result7 || libp) ;
}

// automatic copy constructor
static int G__LAPPDRootDict_215_0_20(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)

{
   LAPPDresponse* p;
   void* tmp = (void*) G__int(libp->para[0]);
   p = new LAPPDresponse(*(LAPPDresponse*) tmp);
   result7->obj.i = (long) p;
   result7->ref = (long) p;
   G__set_tagnum(result7,G__get_linked_tagnum(&G__LAPPDRootDictLN_LAPPDresponse));
   return(1 || funcname || hash || result7 || libp) ;
}

// automatic destructor
typedef LAPPDresponse G__TLAPPDresponse;
static int G__LAPPDRootDict_215_0_21(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
   char* gvp = (char*) G__getgvp();
   long soff = G__getstructoffset();
   int n = G__getaryconstruct();
   //
   //has_a_delete: 1
   //has_own_delete1arg: 0
   //has_own_delete2arg: 0
   //
   if (!soff) {
     return(1);
   }
   if (n) {
     if (gvp == (char*)G__PVOID) {
       delete[] (LAPPDresponse*) soff;
     } else {
       G__setgvp((long) G__PVOID);
       for (int i = n - 1; i >= 0; --i) {
         ((LAPPDresponse*) (soff+(sizeof(LAPPDresponse)*i)))->~G__TLAPPDresponse();
       }
       G__setgvp((long)gvp);
     }
   } else {
     if (gvp == (char*)G__PVOID) {
       delete (LAPPDresponse*) soff;
     } else {
       G__setgvp((long) G__PVOID);
       ((LAPPDresponse*) (soff))->~G__TLAPPDresponse();
       G__setgvp((long)gvp);
     }
   }
   G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

// automatic assignment operator
static int G__LAPPDRootDict_215_0_22(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
   LAPPDresponse* dest = (LAPPDresponse*) G__getstructoffset();
   *dest = *(LAPPDresponse*) libp->para[0].ref;
   const LAPPDresponse& obj = *dest;
   result7->ref = (long) (&obj);
   result7->obj.i = (long) (&obj);
   return(1 || funcname || hash || result7 || libp) ;
}


/* Setting up global function */

/*********************************************************
* Member function Stub
*********************************************************/

/* LAPPDresponse */

/*********************************************************
* Global function Stub
*********************************************************/

/*********************************************************
* Get size of pointer to member function
*********************************************************/
class G__Sizep2memfuncLAPPDRootDict {
 public:
  G__Sizep2memfuncLAPPDRootDict(): p(&G__Sizep2memfuncLAPPDRootDict::sizep2memfunc) {}
    size_t sizep2memfunc() { return(sizeof(p)); }
  private:
    size_t (G__Sizep2memfuncLAPPDRootDict::*p)();
};

size_t G__get_sizep2memfuncLAPPDRootDict()
{
  G__Sizep2memfuncLAPPDRootDict a;
  G__setsizep2memfunc((int)a.sizep2memfunc());
  return((size_t)a.sizep2memfunc());
}


/*********************************************************
* virtual base class offset calculation interface
*********************************************************/

   /* Setting up class inheritance */

/*********************************************************
* Inheritance information setup/
*********************************************************/
extern "C" void G__cpp_setup_inheritanceLAPPDRootDict() {

   /* Setting up class inheritance */
   if(0==G__getnumbaseclass(G__get_linked_tagnum(&G__LAPPDRootDictLN_LAPPDresponse))) {
     LAPPDresponse *G__Lderived;
     G__Lderived=(LAPPDresponse*)0x1000;
     {
       TObject *G__Lpbase=(TObject*)G__Lderived;
       G__inheritance_setup(G__get_linked_tagnum(&G__LAPPDRootDictLN_LAPPDresponse),G__get_linked_tagnum(&G__LAPPDRootDictLN_TObject),(long)G__Lpbase-(long)G__Lderived,1,1);
     }
   }
}

/*********************************************************
* typedef information setup/
*********************************************************/
extern "C" void G__cpp_setup_typetableLAPPDRootDict() {

   /* Setting up typedef entry */
   G__search_typename2("Version_t",115,-1,0,-1);
   G__setnewtype(-1,"Class version identifier (short)",0);
   G__search_typename2("vector<ROOT::TSchemaHelper>",117,G__get_linked_tagnum(&G__LAPPDRootDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<const_iterator>",117,G__get_linked_tagnum(&G__LAPPDRootDictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__LAPPDRootDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<iterator>",117,G__get_linked_tagnum(&G__LAPPDRootDictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__LAPPDRootDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("vector<TVirtualArray*>",117,G__get_linked_tagnum(&G__LAPPDRootDictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<const_iterator>",117,G__get_linked_tagnum(&G__LAPPDRootDictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__LAPPDRootDictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<iterator>",117,G__get_linked_tagnum(&G__LAPPDRootDictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__LAPPDRootDictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("TVectorT<Float_t>",117,G__get_linked_tagnum(&G__LAPPDRootDictLN_TVectorTlEfloatgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("TVectorT<Double_t>",117,G__get_linked_tagnum(&G__LAPPDRootDictLN_TVectorTlEdoublegR),0,-1);
   G__setnewtype(-1,NULL,0);
}

/*********************************************************
* Data Member information setup/
*********************************************************/

   /* Setting up class,struct,union tag member variable */

   /* LAPPDresponse */
static void G__setup_memvarLAPPDresponse(void) {
   G__tag_memvar_setup(G__get_linked_tagnum(&G__LAPPDRootDictLN_LAPPDresponse));
   { LAPPDresponse *p; p=(LAPPDresponse*)0x1000; if (p) { }
   G__memvar_setup((void*)0,100,0,0,-1,-1,-1,4,"_freezetime=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__LAPPDRootDictLN_TH1D),-1,-1,4,"_templatepulse=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__LAPPDRootDictLN_TH1D),-1,-1,4,"_PHD=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__LAPPDRootDictLN_TH1D),-1,-1,4,"_pulsewidth=",0,(char*)NULL);
   G__memvar_setup((void*)0,100,0,0,-1,-1,-1,4,"_noiselevel=",0,(char*)NULL);
   G__memvar_setup((void*)0,105,0,0,-1,-1,-1,4,"_nsamples=",0,(char*)NULL);
   G__memvar_setup((void*)0,100,0,0,-1,-1,-1,4,"_samplewidth=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,2,0,G__get_linked_tagnum(&G__LAPPDRootDictLN_TH1D),-1,-1,4,"StripResponse_neg=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,2,0,G__get_linked_tagnum(&G__LAPPDRootDictLN_TH1D),-1,-1,4,"StripResponse_pos=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__LAPPDRootDictLN_TClass),G__defined_typename("atomic_TClass_ptr"),-2,4,"fgIsA=",0,(char*)NULL);
   }
   G__tag_memvar_reset();
}

extern "C" void G__cpp_setup_memvarLAPPDRootDict() {
}
/***********************************************************
************************************************************
************************************************************
************************************************************
************************************************************
************************************************************
************************************************************
***********************************************************/

/*********************************************************
* Member function information setup for each class
*********************************************************/
static void G__setup_memfuncLAPPDresponse(void) {
   /* LAPPDresponse */
   G__tag_memfunc_setup(G__get_linked_tagnum(&G__LAPPDRootDictLN_LAPPDresponse));
   G__memfunc_setup("LAPPDresponse",1248,G__LAPPDRootDict_215_0_1, 105, G__get_linked_tagnum(&G__LAPPDRootDictLN_LAPPDresponse), -1, 0, 0, 1, 1, 0, "", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("SetFreezeTime",1308,G__LAPPDRootDict_215_0_2, 121, -1, -1, 0, 1, 1, 1, 0, "d - - 0 - freezetime", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("AddPhoton",897,G__LAPPDRootDict_215_0_3, 121, -1, -1, 0, 3, 1, 1, 0, 
"d - - 0 - trans d - - 0 - para "
"d - - 0 - time", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("CalcSinglePhotonTrace",2108,G__LAPPDRootDict_215_0_4, 85, G__get_linked_tagnum(&G__LAPPDRootDictLN_TH1D), -1, 0, 5, 1, 1, 0, 
"i - - 0 - CHnumber d - - 0 - trans "
"d - - 0 - para d - - 0 - time "
"i - - 0 - parity", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("GetTrace",783,G__LAPPDRootDict_215_0_5, 85, G__get_linked_tagnum(&G__LAPPDRootDictLN_TH1D), -1, 0, 2, 1, 1, 0, 
"i - - 0 - CHnumber i - - 0 - parity", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("FindNearestStrip",1637,(G__InterfaceMethod) NULL, 105, -1, -1, 0, 1, 1, 4, 0, "d - - 0 - trans", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("TransStripCenter",1659,(G__InterfaceMethod) NULL, 100, -1, -1, 0, 1, 1, 4, 0, "i - - 0 - CHnum", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("Class",502,G__LAPPDRootDict_215_0_8, 85, G__get_linked_tagnum(&G__LAPPDRootDictLN_TClass), -1, 0, 0, 3, 1, 0, "", (char*)NULL, (void*) G__func2void( (TClass* (*)())(&LAPPDresponse::Class) ), 0);
   G__memfunc_setup("Class_Name",982,G__LAPPDRootDict_215_0_9, 67, -1, -1, 0, 0, 3, 1, 1, "", (char*)NULL, (void*) G__func2void( (const char* (*)())(&LAPPDresponse::Class_Name) ), 0);
   G__memfunc_setup("Class_Version",1339,G__LAPPDRootDict_215_0_10, 115, -1, G__defined_typename("Version_t"), 0, 0, 3, 1, 0, "", (char*)NULL, (void*) G__func2void( (Version_t (*)())(&LAPPDresponse::Class_Version) ), 0);
   G__memfunc_setup("Dictionary",1046,G__LAPPDRootDict_215_0_11, 121, -1, -1, 0, 0, 3, 1, 0, "", (char*)NULL, (void*) G__func2void( (void (*)())(&LAPPDresponse::Dictionary) ), 0);
   G__memfunc_setup("IsA",253,(G__InterfaceMethod) NULL,85, G__get_linked_tagnum(&G__LAPPDRootDictLN_TClass), -1, 0, 0, 1, 1, 8, "", (char*)NULL, (void*) NULL, 1);
   G__memfunc_setup("ShowMembers",1132,(G__InterfaceMethod) NULL,121, -1, -1, 0, 1, 1, 1, 0, "u 'TMemberInspector' - 1 - -", (char*)NULL, (void*) NULL, 1);
   G__memfunc_setup("Streamer",835,(G__InterfaceMethod) NULL,121, -1, -1, 0, 1, 1, 1, 0, "u 'TBuffer' - 1 - -", (char*)NULL, (void*) NULL, 1);
   G__memfunc_setup("StreamerNVirtual",1656,G__LAPPDRootDict_215_0_15, 121, -1, -1, 0, 1, 1, 1, 0, "u 'TBuffer' - 1 - ClassDef_StreamerNVirtual_b", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("DeclFileName",1145,G__LAPPDRootDict_215_0_16, 67, -1, -1, 0, 0, 3, 1, 1, "", (char*)NULL, (void*) G__func2void( (const char* (*)())(&LAPPDresponse::DeclFileName) ), 0);
   G__memfunc_setup("ImplFileLine",1178,G__LAPPDRootDict_215_0_17, 105, -1, -1, 0, 0, 3, 1, 0, "", (char*)NULL, (void*) G__func2void( (int (*)())(&LAPPDresponse::ImplFileLine) ), 0);
   G__memfunc_setup("ImplFileName",1171,G__LAPPDRootDict_215_0_18, 67, -1, -1, 0, 0, 3, 1, 1, "", (char*)NULL, (void*) G__func2void( (const char* (*)())(&LAPPDresponse::ImplFileName) ), 0);
   G__memfunc_setup("DeclFileLine",1152,G__LAPPDRootDict_215_0_19, 105, -1, -1, 0, 0, 3, 1, 0, "", (char*)NULL, (void*) G__func2void( (int (*)())(&LAPPDresponse::DeclFileLine) ), 0);
   // automatic copy constructor
   G__memfunc_setup("LAPPDresponse", 1248, G__LAPPDRootDict_215_0_20, (int) ('i'), G__get_linked_tagnum(&G__LAPPDRootDictLN_LAPPDresponse), -1, 0, 1, 1, 1, 0, "u 'LAPPDresponse' - 11 - -", (char*) NULL, (void*) NULL, 0);
   // automatic destructor
   G__memfunc_setup("~LAPPDresponse", 1374, G__LAPPDRootDict_215_0_21, (int) ('y'), -1, -1, 0, 0, 1, 1, 0, "", (char*) NULL, (void*) NULL, 1);
   // automatic assignment operator
   G__memfunc_setup("operator=", 937, G__LAPPDRootDict_215_0_22, (int) ('u'), G__get_linked_tagnum(&G__LAPPDRootDictLN_LAPPDresponse), -1, 1, 1, 1, 1, 0, "u 'LAPPDresponse' - 11 - -", (char*) NULL, (void*) NULL, 0);
   G__tag_memfunc_reset();
}


/*********************************************************
* Member function information setup
*********************************************************/
extern "C" void G__cpp_setup_memfuncLAPPDRootDict() {
}

/*********************************************************
* Global variable information setup for each class
*********************************************************/
static void G__cpp_setup_global0() {

   /* Setting up global variables */
   G__resetplocal();

}

static void G__cpp_setup_global1() {
}

static void G__cpp_setup_global2() {
}

static void G__cpp_setup_global3() {

   G__resetglobalenv();
}
extern "C" void G__cpp_setup_globalLAPPDRootDict() {
  G__cpp_setup_global0();
  G__cpp_setup_global1();
  G__cpp_setup_global2();
  G__cpp_setup_global3();
}

/*********************************************************
* Global function information setup for each class
*********************************************************/
static void G__cpp_setup_func0() {
   G__lastifuncposition();

}

static void G__cpp_setup_func1() {
}

static void G__cpp_setup_func2() {
}

static void G__cpp_setup_func3() {
}

static void G__cpp_setup_func4() {
}

static void G__cpp_setup_func5() {
}

static void G__cpp_setup_func6() {
}

static void G__cpp_setup_func7() {
}

static void G__cpp_setup_func8() {
}

static void G__cpp_setup_func9() {
}

static void G__cpp_setup_func10() {
}

static void G__cpp_setup_func11() {
}

static void G__cpp_setup_func12() {
}

static void G__cpp_setup_func13() {
}

static void G__cpp_setup_func14() {

   G__resetifuncposition();
}

extern "C" void G__cpp_setup_funcLAPPDRootDict() {
  G__cpp_setup_func0();
  G__cpp_setup_func1();
  G__cpp_setup_func2();
  G__cpp_setup_func3();
  G__cpp_setup_func4();
  G__cpp_setup_func5();
  G__cpp_setup_func6();
  G__cpp_setup_func7();
  G__cpp_setup_func8();
  G__cpp_setup_func9();
  G__cpp_setup_func10();
  G__cpp_setup_func11();
  G__cpp_setup_func12();
  G__cpp_setup_func13();
  G__cpp_setup_func14();
}

/*********************************************************
* Class,struct,union,enum tag information setup
*********************************************************/
/* Setup class/struct taginfo */
G__linked_taginfo G__LAPPDRootDictLN_TClass = { "TClass" , 99 , -1 };
G__linked_taginfo G__LAPPDRootDictLN_TBuffer = { "TBuffer" , 99 , -1 };
G__linked_taginfo G__LAPPDRootDictLN_TMemberInspector = { "TMemberInspector" , 99 , -1 };
G__linked_taginfo G__LAPPDRootDictLN_TObject = { "TObject" , 99 , -1 };
G__linked_taginfo G__LAPPDRootDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR = { "vector<ROOT::TSchemaHelper,allocator<ROOT::TSchemaHelper> >" , 99 , -1 };
G__linked_taginfo G__LAPPDRootDictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR = { "reverse_iterator<vector<ROOT::TSchemaHelper,allocator<ROOT::TSchemaHelper> >::iterator>" , 99 , -1 };
G__linked_taginfo G__LAPPDRootDictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR = { "vector<TVirtualArray*,allocator<TVirtualArray*> >" , 99 , -1 };
G__linked_taginfo G__LAPPDRootDictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR = { "reverse_iterator<vector<TVirtualArray*,allocator<TVirtualArray*> >::iterator>" , 99 , -1 };
G__linked_taginfo G__LAPPDRootDictLN_TVectorTlEfloatgR = { "TVectorT<float>" , 99 , -1 };
G__linked_taginfo G__LAPPDRootDictLN_TVectorTlEdoublegR = { "TVectorT<double>" , 99 , -1 };
G__linked_taginfo G__LAPPDRootDictLN_TH1D = { "TH1D" , 99 , -1 };
G__linked_taginfo G__LAPPDRootDictLN_LAPPDresponse = { "LAPPDresponse" , 99 , -1 };

/* Reset class/struct taginfo */
extern "C" void G__cpp_reset_tagtableLAPPDRootDict() {
  G__LAPPDRootDictLN_TClass.tagnum = -1 ;
  G__LAPPDRootDictLN_TBuffer.tagnum = -1 ;
  G__LAPPDRootDictLN_TMemberInspector.tagnum = -1 ;
  G__LAPPDRootDictLN_TObject.tagnum = -1 ;
  G__LAPPDRootDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR.tagnum = -1 ;
  G__LAPPDRootDictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR.tagnum = -1 ;
  G__LAPPDRootDictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR.tagnum = -1 ;
  G__LAPPDRootDictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR.tagnum = -1 ;
  G__LAPPDRootDictLN_TVectorTlEfloatgR.tagnum = -1 ;
  G__LAPPDRootDictLN_TVectorTlEdoublegR.tagnum = -1 ;
  G__LAPPDRootDictLN_TH1D.tagnum = -1 ;
  G__LAPPDRootDictLN_LAPPDresponse.tagnum = -1 ;
}


extern "C" void G__cpp_setup_tagtableLAPPDRootDict() {

   /* Setting up class,struct,union tag entry */
   G__get_linked_tagnum_fwd(&G__LAPPDRootDictLN_TClass);
   G__get_linked_tagnum_fwd(&G__LAPPDRootDictLN_TBuffer);
   G__get_linked_tagnum_fwd(&G__LAPPDRootDictLN_TMemberInspector);
   G__get_linked_tagnum_fwd(&G__LAPPDRootDictLN_TObject);
   G__get_linked_tagnum_fwd(&G__LAPPDRootDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR);
   G__get_linked_tagnum_fwd(&G__LAPPDRootDictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR);
   G__get_linked_tagnum_fwd(&G__LAPPDRootDictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR);
   G__get_linked_tagnum_fwd(&G__LAPPDRootDictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR);
   G__get_linked_tagnum_fwd(&G__LAPPDRootDictLN_TVectorTlEfloatgR);
   G__get_linked_tagnum_fwd(&G__LAPPDRootDictLN_TVectorTlEdoublegR);
   G__get_linked_tagnum_fwd(&G__LAPPDRootDictLN_TH1D);
   G__tagtable_setup(G__get_linked_tagnum_fwd(&G__LAPPDRootDictLN_LAPPDresponse),sizeof(LAPPDresponse),-1,29952,(char*)NULL,G__setup_memvarLAPPDresponse,G__setup_memfuncLAPPDresponse);
}
extern "C" void G__cpp_setupLAPPDRootDict(void) {
  G__check_setup_version(30051515,"G__cpp_setupLAPPDRootDict()");
  G__set_cpp_environmentLAPPDRootDict();
  G__cpp_setup_tagtableLAPPDRootDict();

  G__cpp_setup_inheritanceLAPPDRootDict();

  G__cpp_setup_typetableLAPPDRootDict();

  G__cpp_setup_memvarLAPPDRootDict();

  G__cpp_setup_memfuncLAPPDRootDict();
  G__cpp_setup_globalLAPPDRootDict();
  G__cpp_setup_funcLAPPDRootDict();

   if(0==G__getsizep2memfunc()) G__get_sizep2memfuncLAPPDRootDict();
  return;
}
class G__cpp_setup_initLAPPDRootDict {
  public:
    G__cpp_setup_initLAPPDRootDict() { G__add_setup_func("LAPPDRootDict",(G__incsetup)(&G__cpp_setupLAPPDRootDict)); G__call_setup_funcs(); }
   ~G__cpp_setup_initLAPPDRootDict() { G__remove_setup_func("LAPPDRootDict"); }
};
G__cpp_setup_initLAPPDRootDict G__cpp_setup_initializerLAPPDRootDict;

