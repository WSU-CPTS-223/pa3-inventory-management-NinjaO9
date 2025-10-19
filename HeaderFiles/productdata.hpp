#include "libs.h"
#ifndef PROD_DATA_H
#define PROD_DATA_H

typedef enum attributes
{
    UNIQ_ID,
    PRODUCT_NAME,
    BRAND_NAME,
    ASIN,
    CATEGORY,
    UPC_EAN_CODE,
    LIST_PRICE,
    SELLING_PRICE,
    QUANTITY,
    MODEL_NUMBER,
    ABOUT_PRODUCT,
    PRODUCT_SPECIFICATION,
    TECHNICAL_DETAILS,
    SHIPPING_WEIGHT,
    PRODUCT_DIMENSIONS,
    IMAGE,
    VARIANTS,
    SKU,
    PRODUCT_URL,
    STOCK,
    PRODUCT_DETAILS,
    DIMENSIONS,
    COLOR,
    INGREDIENTS,
    DIRECTION_TO_USE,
    IS_AMAZON_SELLER,
    SIZE_QUANTITY_VARIANT,
    PRODUCT_DESCRIPTION,
    LAST
}Attributes;

// Might want to change some things, like datatypes used for categories, etc. Thats a decision I can change later if I see fit, though
class ProductData
{

    public:

    ProductData() : _UniqId("N/A"), _ProductName("N/A"), _BrandName("N/A"), _Asin("N/A"), _Categories("N/A"), _UpcEanCode("N/A"), _ListPrice("N/A"), _SellingPrice("N/A"), _Quantity("N/A"), _ModelNumber("N/A"), _AboutProduct("N/A"), _ProductSpecifications("N/A"), _TechnicalDetails("N/A"), _ShippingWeight("N/A"), _ProductDimensions("N/A"), _Image("N/A"), _Variants("N/A"), _Sku("N/A"), _ProductUrl("N/A"), _Dimensions("N/A"), _Color("N/A"), _Ingredients("N/A"), _DirectionToUse("N/A"), _IsAmazonSeller("N/A"), _SizeQuantityVariant("N/A"), _ProductDescription("N/A"){};

    ProductData(string attr[]);

    ProductData(string nUID, string nPN, string nBN, string nAsin, string nCategories, string nUEC, string nLPrice, string nSPrice, string nQuant, string nModNum, string nAbtProd, string nProdSpec, string nTechDet, string nShipW, string nProdDim, string nImage, string nVars, string nSku, string nProdUrl, string nDims, string nColor, string nIngredients, string nDirToUse, string nIsAmaSell, string nSQuanVar, string nProdDesc)
    : _UniqId(nUID), _ProductName(nPN), _BrandName(nBN), _Asin(nAsin), _Categories(nCategories), _UpcEanCode(nUEC), _ListPrice(nLPrice), _SellingPrice(nSPrice), _Quantity(nQuant), _ModelNumber(nModNum), _AboutProduct(nAbtProd), _ProductSpecifications(nProdSpec), _TechnicalDetails(nTechDet), _ShippingWeight(nShipW), _ProductDimensions(nProdDim), _Image(nImage), _Variants(nVars), _Sku(nSku), _ProductUrl(nProdUrl), _Dimensions(nDims), _Color(nColor), _Ingredients(nIngredients), _DirectionToUse(nDirToUse), _IsAmazonSeller(nIsAmaSell), _SizeQuantityVariant(nSQuanVar), _ProductDescription(nProdDesc){}
    // Long ass constructor of doom

    ProductData(const ProductData& other) = default;

    ~ProductData() = default;

    string get_uniqid() const {return _UniqId;}

    string get_productname() const {return _ProductName;}

    string get_brandname() const {return _BrandName;}

    string get_asin() const {return _Asin;}

    string get_categories() const {return _Categories;}

    string get_upceancode() const {return _UpcEanCode;}

    string get_listprice() const {return _ListPrice;}

    string get_sellingprice() const {return _SellingPrice;}

    string get_quantity() const {return _Quantity;}

    string get_modelnumber() const {return _ModelNumber;}

    string get_about() const {return _AboutProduct;}

    string get_prodspecs() const {return _ProductSpecifications;}

    string get_techdetails() const {return _TechnicalDetails;}

    string get_shippingweight() const {return _ShippingWeight;}

    string get_proddimensions() const {return _ProductDimensions;}

    string get_image() const {return _Image;}

    string get_variants() const {return _Variants;}

    string get_sku() const {return _Sku;}

    string get_produrl() const {return _ProductUrl;}

    string get_stock() const {return _Stock;}

    string get_proddetails() const {return _ProductDetails;}

    string get_dimensions() const {return _Dimensions;}

    string get_color() const {return _Color;}

    string get_ingredients() const {return _Ingredients;}

    string get_directiontouse() const {return _DirectionToUse;}

    string get_isamazonseller() const {return _IsAmazonSeller;}

    string get_sizequantityvariant() const {return _SizeQuantityVariant;}

    string get_productdescription() const {return _ProductDescription;}

    bool operator==(ProductData& other) {return _UniqId == other.get_uniqid();}

    bool operator!=(ProductData& other) {return _UniqId != other.get_uniqid();}

    
    private:
    // _AboutProduct, _Categories <- Might be lists
    string _UniqId, _ProductName, _BrandName,
     _Asin, _Categories, _UpcEanCode, _ListPrice, 
     _SellingPrice, _Quantity, _ModelNumber, _AboutProduct, 
     _ProductSpecifications, _TechnicalDetails, _ShippingWeight,
      _ProductDimensions, _Image, _Variants, _Sku, _ProductUrl, 
      _Stock, _ProductDetails, _Dimensions, _Color, _Ingredients, 
      _DirectionToUse, _IsAmazonSeller, _SizeQuantityVariant, 
      _ProductDescription;

};

ostream& operator<<(ostream& lhs, const ProductData& rhs);

#endif